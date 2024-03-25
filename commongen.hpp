/**
 * Generates common file.
*/

#pragma once

#include <iostream>
#include "antlr4-runtime.h"
#include "woditextBaseVisitor.h"
#include "commonfile.hpp"
#include "commonevent.hpp"
#include "symboltable.hpp"

class CommonGen : public woditextBaseVisitor {
private:
	static const int VAR_STACK_START = 10;
	static const int TEMP_STACK_START = 98;
	static const int INT_RETURN_INDEX = 99;
	static const int STR_RETURN_INDEX = 9;

	// Where the engine begins to interpret integers as local references.
	static const int32_t CSELF_YOBIDASI = 1600000;

	CommonEvent* current_event = nullptr;
	int var_stackpos = VAR_STACK_START;
	int highest_var_stackpos = VAR_STACK_START;
	int temp_stackpos = TEMP_STACK_START;
	int lowest_temp_stackpos = TEMP_STACK_START;
	var_type return_type = t_void;
	SymbolTable st;

	void error(antlr4::ParserRuleContext *ctx, std::string message) const {
		std::cout 
			<< "ERROR:  " << message									<< std::endl
			<< "common: " << current_event->name						<< std::endl
			<< "line:   " << ctx->getStart()->getLine()					<< std::endl
			<< "col:    " << ctx->getStart()->getCharPositionInLine()	<< std::endl;
		exit(1);
	}

	void error(std::string message) const {
		std::cout
			<< "ERROR:  " << message << std::endl
			<< "common: " << current_event->name << std::endl;
		exit(1);
	}

	/**
	* Declare a new integer variable, and insert it into the current scope.
	* Errors if this would cause a redeclaration.
	* @param name	Name of the variable.
	* @return		A copy of the inserted VarSymbol.
	*/
	VarSymbol new_var(std::string name) {
		if (highest_var_stackpos >= lowest_temp_stackpos) {
			error("no more space for variables");
		}
		int32_t yobidasi = CSELF_YOBIDASI + var_stackpos;
		current_event->cself_names.at(var_stackpos) = name;
		VarSymbol sym = VarSymbol(name, yobidasi, t_int);
		if (!st.insert(sym)) error("redeclaration of " + name);
		var_stackpos++;
		highest_var_stackpos = std::max(var_stackpos, highest_var_stackpos);
		return sym;
	}

	/**
	* Get new temporary.
	* @return	WodNumber value of the temporary.
	*/
	WodNumber new_temp() {
		if (highest_var_stackpos >= lowest_temp_stackpos) {
			error("no more space for temp variables");
		}
		int32_t yobidasi = CSELF_YOBIDASI + temp_stackpos;
		current_event->cself_names.at(temp_stackpos) = "__t" + std::to_string(temp_stackpos);
		temp_stackpos--;
		lowest_temp_stackpos = std::min(temp_stackpos, lowest_temp_stackpos);
		return WodNumber(yobidasi, true);
	}

	// TODO: broken
	WodNumber eval_expr(woditextParser::ExprContext* ctx) {
		try {
			WodNumber result = std::any_cast<WodNumber>(ctx->accept(this));
			return result;
		}
		catch (const std::bad_any_cast&) {
			error(ctx, "expr did not return a WodNumber");
		}
		return WodNumber(0);
	}

public:
	CommonFile cf;

	std::any visitCommon(woditextParser::CommonContext* ctx) override {
		// reset state
		var_stackpos = VAR_STACK_START;
		temp_stackpos = TEMP_STACK_START;
		lowest_temp_stackpos = TEMP_STACK_START;
		st = SymbolTable();

		// make new commonevent
		current_event = cf.add_common(std::make_unique<CommonEvent>());

		// handle return type
		current_event->name = ctx->ID()->getText();
		if (ctx->returntype()->T_VOID()) {
			return_type = t_void;
		}
		else if (ctx->returntype()->T_INT()) {
			return_type = t_int;
			current_event->return_cself_id = INT_RETURN_INDEX;
		}
		else if (ctx->returntype()->T_STR()) {
			return_type = t_str;
			current_event->return_cself_id = STR_RETURN_INDEX;
		}
		else error(ctx, "unknown return type");
		
		// handle params
		std::vector<woditextParser::ParamContext*> params = ctx->param();
		for (auto iter = params.begin(); iter != params.end(); iter++) {
			std::string name = (*iter)->ID()->getText();
			if ((*iter)->vartype()->T_INT()) {
				int index = current_event->new_int_param(name);
				if (index < 0) error(ctx, "too many int parameters in common definition");
				st.insert(VarSymbol(name, CSELF_YOBIDASI + index, t_int));
			}
			else if ((*iter)->vartype()->T_STR()) {
				int index = current_event->new_str_param(name);
				if (index < 0) error(ctx, "too many str parameters in common definition");
				st.insert(VarSymbol(name, CSELF_YOBIDASI + index, t_str));
			}
			else {
				error(ctx, "unexpected param type");
			}
		}

		// visit code
		ctx->codeblock()->accept(this);

		// if a common is completely blank, the engine will determine commonevent.dat as corrupted
		// append an empty line at the end of the common to alleviate this
		current_event->append(std::make_unique<EmptyLine>());

		return std::any();
	}

	std::any visitReturn(woditextParser::ReturnContext* ctx) override {
		int saved_temp_pos = temp_stackpos;
		WodNumber rhs = eval_expr(ctx->expr());
		temp_stackpos = saved_temp_pos;

		// assign to var
		current_event->append(
			std::make_unique<ArithLine>(
				CSELF_YOBIDASI + INT_RETURN_INDEX,
				rhs, 0,
				ArithLine::assign_eq | ArithLine::op_plus
			)
		);
		current_event->append(std::make_unique<ReturnLine>());

		return std::any();
	}

	std::any visitIfstmt(woditextParser::IfstmtContext* ctx) override {
		int saved_temp_pos = temp_stackpos;
		WodNumber condition = eval_expr(ctx->expr());
		temp_stackpos = saved_temp_pos;

		std::unique_ptr<IntIfHeadLine> headline = std::make_unique<IntIfHeadLine>(condition, 0, IntIfHeadLine::op_neq);
		if (ctx->stmt(1)) headline->set_else_branch(true);
		
		current_event->append(std::move(headline));
		current_event->append(std::make_unique<BranchLine>(1));
		
		st.open_scope();
		ctx->stmt(0)->accept(this);
		current_event->append(std::make_unique<EmptyLine>());
		st.close_scope();

		if (ctx->stmt(1)) {
			current_event->append(std::make_unique<ElseBranchLine>());
			st.open_scope();
			ctx->stmt(1)->accept(this);
			current_event->append(std::make_unique<EmptyLine>());
			st.close_scope();
		}

		current_event->append(std::make_unique<EndBranchLine>());

		return std::any();
	}

	std::any visitAssign(woditextParser::AssignContext* ctx) override {
		
		std::string varname = ctx->lhs()->ID()->getText();
		if (ctx->lhs()->vartype()) {
			// if lhs has a variable type, statement is a declaration; create new variable
			new_var(varname);
		}
		VarSymbol* dest_symbol = st.lookup(varname);

		// get assignment type
		ArithLine::assign_type assign = ArithLine::assign_eq;
		if (ctx->AS_PEQ()) assign = ArithLine::assign_plus_eq;
		else if (ctx->AS_MEQ()) assign = ArithLine::assign_minus_eq;
		else if (ctx->AS_TEQ()) assign = ArithLine::assign_times_eq;
		else if (ctx->AS_DEQ()) assign = ArithLine::assign_div_eq;

		// eval
		int saved_temp_pos = temp_stackpos;
		WodNumber rhs = eval_expr(ctx->expr());
		temp_stackpos = saved_temp_pos;

		// assign to var
		current_event->append(
			std::make_unique<ArithLine>(
				WodNumber(dest_symbol->yobidasi, true),
				rhs, 0,
				assign | ArithLine::op_plus
			)
		);

		// restore temp stack
		return std::any();
	}

	std::any visitNumExpr(woditextParser::NumExprContext* ctx) override {
		std::string text = ctx->NUM()->getText();
		try {
			return WodNumber(static_cast<int32_t>(stoi(text, 0)));
		}
		catch (const std::out_of_range&) {
			error(ctx, "integer literal " + text + " is too large to fit in a signed 32-bit integer");
		}
		return std::any();
	}
	
	std::any visitIdExpr(woditextParser::IdExprContext* ctx) override {
		VarSymbol* symbol = st.lookup(ctx->ID()->getText());
		if (symbol) return WodNumber(symbol->yobidasi, true);
		else error(ctx, "id: lookup failed");
		return std::any();
	}
	
	std::any visitParenExpr(woditextParser::ParenExprContext* ctx) override {
		return ctx->expr()->accept(this);
	}
	
	/**
	* Negates expr (since that is the only unop)
	* @return	yobidasi of the cself in which the negated result is stored
	*/
	std::any visitUnopExpr(woditextParser::UnopExprContext* ctx) override {
		// eval
		int saved_temp_pos = temp_stackpos;
		WodNumber arg = eval_expr(ctx->expr());
		temp_stackpos = saved_temp_pos;

		WodNumber tempvar = new_temp();
		current_event->append(
			std::make_unique<ArithLine>(
				tempvar,
				0, arg,
				ArithLine::assign_eq | ArithLine::op_minus
			)
		);

		return tempvar;
	}
	
	/**
	* @return	yobidasi of the cself in which the result is stored
	*/
	std::any visitBinopExpr(woditextParser::BinopExprContext* ctx) override {
		int saved_temp_pos = temp_stackpos;
		WodNumber left = eval_expr(ctx->expr(0));
		WodNumber right = eval_expr(ctx->expr(1));
		temp_stackpos = saved_temp_pos;

		ArithLine::arith_op op = ArithLine::op_plus;
		if		(ctx->OP_PLUS())	op = ArithLine::op_plus;
		else if (ctx->OP_MINUS())	op = ArithLine::op_minus;
		else if (ctx->OP_TIMES())	op = ArithLine::op_times;
		else if (ctx->OP_DIV())		op = ArithLine::op_div;
		else if (ctx->OP_MOD())		op = ArithLine::op_mod;
		else if (ctx->OP_AMP())		op = ArithLine::op_bitand;
		else error(ctx, "no matching op");

		WodNumber tempvar = new_temp();
		current_event->append(
			std::make_unique<ArithLine>(
				tempvar, left, right, ArithLine::assign_eq | op
			)
		);
		
		return tempvar;
	}

	std::any visitBinopRelExpr(woditextParser::BinopRelExprContext* ctx) override {
		int saved_temp_pos = temp_stackpos;
		WodNumber left = eval_expr(ctx->expr(0));
		WodNumber right = eval_expr(ctx->expr(1));
		temp_stackpos = saved_temp_pos;

		IntIfHeadLine::comp_op op = IntIfHeadLine::op_gt;
		if (ctx->OP_LT()) op = IntIfHeadLine::op_lt;
		else if (ctx->OP_LTE()) op = IntIfHeadLine::op_lte;
		else if (ctx->OP_GT()) op = IntIfHeadLine::op_gt;
		else if (ctx->OP_GTE()) op = IntIfHeadLine::op_gte;
		else if (ctx->OP_EQ()) op = IntIfHeadLine::op_eq;
		else if (ctx->OP_NEQ()) op = IntIfHeadLine::op_neq;
		else error(ctx, "no matching relop");

		std::unique_ptr<IntIfHeadLine> headline = std::make_unique<IntIfHeadLine>(left, right, op);
		headline->set_else_branch(true);

		current_event->append(std::move(headline));
		current_event->append(std::make_unique<BranchLine>(1));

		WodNumber tempvar = new_temp();
		current_event->append(std::make_unique<ArithLine>(
				tempvar, 1, 0, ArithLine::assign_eq | ArithLine::op_plus));

		current_event->append(std::make_unique<ElseBranchLine>());
		current_event->append(std::make_unique<ArithLine>(
			tempvar, 0, 0, ArithLine::assign_eq | ArithLine::op_plus));

		return tempvar;
	}

	std::any visitDecl(woditextParser::DeclContext* ctx) override {
		std::string varname = ctx->ID()->getText();
		new_var(varname);

		return std::any();
	}
};