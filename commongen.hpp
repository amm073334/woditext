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
#include "doublestack.hpp"

class CommonGen : public woditextBaseVisitor {
private:
	static const int INT_VAR_STACK_START = 10;
	static const int INT_TEMP_STACK_START = 98;
	static const int INT_RETURN_INDEX = 99;

	static const int STR_VAR_STACK_START = 5;
	static const int STR_TEMP_STACK_START = 8;
	static const int STR_RETURN_INDEX = 9;

	// Where the engine begins to interpret integers as local references.
	static const int32_t CSELF_YOBIDASI = 1600000;

	CommonEvent* current_event = nullptr;
	var_type curr_return_type = t_void;

	DoubleStack int_stack = DoubleStack(INT_VAR_STACK_START, INT_TEMP_STACK_START);
	DoubleStack str_stack = DoubleStack(STR_VAR_STACK_START, STR_TEMP_STACK_START);
	
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
	* Declare a new variable, and insert it into the current scope.
	* Errors if this would cause a redeclaration.
	* @param name	Name of the variable.
	* @param ty		Type of the variable.
	* @return		A copy of the inserted VarSymbol.
	*/
	VarSymbol new_var(std::string name, var_type ty) {
		assert(ty != t_void);

		int stackpos;
		if (ty == t_int) stackpos = int_stack.push_var();
		else /* t_str */ stackpos = str_stack.push_var();

		int32_t yobidasi = CSELF_YOBIDASI + stackpos;
		current_event->cself_names.at(stackpos) = name;
		VarSymbol sym = VarSymbol(name, yobidasi, ty);
		if (!st.insert(sym)) error("redeclaration of " + name);
		return sym;
	}

	/**
	* Get new temporary.
	* @param ty	Type of the temporary.
	* @return	WodNumber value of the temporary.
	*/
	WodNumber new_temp(var_type ty) {
		assert(ty != t_void);
		
		int stackpos;
		if (ty == t_int) stackpos = int_stack.push_temp();
		else /* t_str */ stackpos = str_stack.push_temp();

		int32_t yobidasi = CSELF_YOBIDASI + stackpos;
		current_event->cself_names.at(stackpos) = "__t" + std::to_string(stackpos);
		return WodNumber(yobidasi, true);
	}

	/**
	* Evaluate expr, but do not create a new temporary to store integer literals.
	* Use this when the WodNumber is to be used in a command that has support for disabling variable references.
	* @param ctx	Expr context
	* @return		WodNumber containing result
	*/
	WodNumber eval_unsafe(woditextParser::ExprContext* ctx) {
		try {
			WodNumber result = std::any_cast<WodNumber>(ctx->accept(this));
			return result;
		}
		catch (const std::bad_any_cast&) {
			error(ctx, "expr did not return a WodNumber");
		}
		return WodNumber(0);
	}

	/**
	* Evaluate expr, creating a new temporary to store large integer literals if necessary.
	* Use this when the WodNumber is to be used in a command that does not have support for disabling references.
	* @param ctx	Expr context
	* @return		WodNumber containing result
	*/
	WodNumber eval_safe(woditextParser::ExprContext* ctx) {
		try {
			WodNumber result = std::any_cast<WodNumber>(ctx->accept(this));
			if (result.should_suppress_yobidasi()) {
				WodNumber t = new_temp(t_int);
				current_event->append(std::make_unique<ArithLine>(t, result.value, 0, ArithLine::af_yobanai1));
				return t;
			}
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
		int_stack = DoubleStack(INT_VAR_STACK_START, INT_TEMP_STACK_START);
		str_stack = DoubleStack(STR_VAR_STACK_START, STR_TEMP_STACK_START);

		// make new commonevent
		current_event = cf.add_common(std::make_unique<CommonEvent>());

		// handle return type
		current_event->name = ctx->ID()->getText();
		if (ctx->returntype()->T_VOID()) {
			curr_return_type = t_void;
		}
		else if (ctx->returntype()->T_INT()) {
			curr_return_type = t_int;
			current_event->return_cself_id = INT_RETURN_INDEX;
		}
		else if (ctx->returntype()->T_STR()) {
			curr_return_type = t_str;
			current_event->return_cself_id = STR_RETURN_INDEX;
		}
		else error(ctx, "unknown return type");
		
		// handle params
		std::vector<var_type> param_types;
		std::vector<woditextParser::ParamContext*> params = ctx->param();
		for (auto iter = params.begin(); iter != params.end(); iter++) {
			std::string name = (*iter)->ID()->getText();
			if ((*iter)->vartype()->T_INT()) {
				int index = current_event->new_int_param(name);
				if (index < 0) error(ctx, "too many int parameters in common definition");
				st.insert(VarSymbol(name, CSELF_YOBIDASI + index, t_int));
				param_types.push_back(t_int);
			}
			else if ((*iter)->vartype()->T_STR()) {
				int index = current_event->new_str_param(name);
				if (index < 0) error(ctx, "too many str parameters in common definition");
				st.insert(VarSymbol(name, CSELF_YOBIDASI + index, t_str));
				param_types.push_back(t_str);
				// for strings, param space is the same as variable space, so add new var here to reflect that
				str_stack.push_var();
			}
			else {
				error(ctx, "unexpected param type");
			}
		}

		// make common event symbol
		st.insert(CommonSymbol(ctx->ID()->getText(), curr_return_type, param_types));

		// visit code
		st.open_scope();
		ctx->codeblock()->accept(this);
		st.close_scope();

		// if a common is completely blank, the engine will determine commonevent.dat as corrupted
		// append an empty line at the end of the common to alleviate this
		current_event->append(std::make_unique<EmptyLine>());

		return std::any();
	}

	std::any visitReturn(woditextParser::ReturnContext* ctx) override {
		if (ctx->expr()) {
			int_stack.save_temp();
			WodNumber rhs = eval_unsafe(ctx->expr());
			int_stack.restore_temp();

			// assign to var
			current_event->append(std::make_unique<ArithLine>(
					CSELF_YOBIDASI + INT_RETURN_INDEX, rhs, 0, 0));
		}
		current_event->append(std::make_unique<ReturnLine>());

		return std::any();
	}

	std::any visitIfstmt(woditextParser::IfstmtContext* ctx) override {
		int_stack.save_temp();
		WodNumber condition = eval_unsafe(ctx->expr());
		int_stack.restore_temp();

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

	std::any visitForeverLoop(woditextParser::ForeverLoopContext* ctx) override {
		current_event->append(std::make_unique<LoopForeverHeadLine>());
		st.open_scope();
		ctx->stmt()->accept(this);
		st.close_scope();
		current_event->append(std::make_unique<EmptyLine>());
		current_event->append(std::make_unique<LoopEndLine>());
		return std::any();
	}

	std::any visitCountLoop(woditextParser::CountLoopContext* ctx) override {
		int_stack.save_temp();
		// this command does not support disabling variable references; do safe eval
		WodNumber arg = eval_safe(ctx->expr());
		int_stack.restore_temp();

		current_event->append(std::make_unique<LoopCountHeadLine>(arg.value));
		st.open_scope();
		ctx->stmt()->accept(this);
		st.close_scope();
		current_event->append(std::make_unique<EmptyLine>());
		current_event->append(std::make_unique<LoopEndLine>());
		return std::any();
	}

	std::any visitBreak(woditextParser::BreakContext* ctx) override {
		current_event->append(std::make_unique<BreakLine>());
		return std::any();
	}

	std::any visitContinue(woditextParser::ContinueContext* ctx) override {
		current_event->append(std::make_unique<ContinueLine>());
		return std::any();
	}

	std::any visitAssign(woditextParser::AssignContext* ctx) override {
		
		// assign to db
		if (woditextParser::DbaccessContext* dbctx = ctx->lhs()->dbaccess()) {
			WodNumber typenum = eval_safe(dbctx->expr(0));
			if (!typenum.is_ref && typenum.value > 99) error(ctx, "attempted to reference DB typenum greater than 99");
			WodNumber datanum = eval_safe(dbctx->expr(1));
			WodNumber valuenum = eval_safe(dbctx->expr(2));

			DBLine::db_type db;
			if (dbctx->CDB())			db = DBLine::cdb;
			else if (dbctx->SDB())		db = DBLine::sdb;
			else /* UDB */				db = DBLine::udb;

			DBLine::assign_type assign;
			if		(ctx->AS_EQ())  assign = DBLine::assign_eq;
			else if (ctx->AS_PEQ()) assign = DBLine::assign_plus_eq;
			else if (ctx->AS_MEQ()) assign = DBLine::assign_minus_eq;
			else if (ctx->AS_TEQ()) assign = DBLine::assign_times_eq;
			else if (ctx->AS_DEQ()) assign = DBLine::assign_div_eq;
			else /* mod eq */		assign = DBLine::assign_mod_eq;

			// eval assignment expr
			int_stack.save_temp();
			WodNumber rhs = eval_safe(ctx->expr());
			int_stack.restore_temp();

			current_event->append(std::make_unique<DBLine>(
				typenum.value, datanum.value, valuenum.value, assign, rhs.value
			));

		} 
		// assign to variable
		else {
			std::string varname = ctx->lhs()->ID()->getText();
			if (ctx->lhs()->vartype()) {
				// if lhs has a variable type, statement is a declaration; create new variable
				if (ctx->lhs()->vartype()->T_INT()) {
					new_var(varname, t_int);
				} else {
					new_var(varname, t_str);
				}
			}
			VarSymbol* dest_symbol = st.lookup_var(varname);
			if (!dest_symbol) {
				error(ctx, "undeclared variable '" + varname + "'");
				return std::any();
			}

			if (dest_symbol->type == t_int) {
				// get assignment type
				ArithLine::assign_type assign;
				if		(ctx->AS_EQ())  assign = ArithLine::assign_eq;
				else if (ctx->AS_PEQ()) assign = ArithLine::assign_plus_eq;
				else if (ctx->AS_MEQ()) assign = ArithLine::assign_minus_eq;
				else if (ctx->AS_TEQ()) assign = ArithLine::assign_times_eq;
				else if (ctx->AS_DEQ()) assign = ArithLine::assign_div_eq;
				else /* mod eq */		assign = ArithLine::assign_mod_eq;

				// eval
				int_stack.save_temp();
				WodNumber rhs = eval_unsafe(ctx->expr());
				int_stack.restore_temp();

				// assign to var
				current_event->append(std::make_unique<ArithLine>(
						WodNumber(dest_symbol->yobidasi, true), rhs, 0, assign));
			}
			else /* string type destination */ {

				StringLine::assign_type assign;
				if (ctx->AS_EQ())  assign = StringLine::assign_eq;
				else if (ctx->AS_PEQ()) assign = StringLine::assign_plus_eq;
				else {
					error(ctx, "cannot use this assignment operator when assigning to a string variable");
					return std::any();
				}

				int_stack.save_temp();
				WodNumber rhs = eval_safe(ctx->expr());
				int_stack.restore_temp();

				current_event->append(std::make_unique<StringLine>(
					dest_symbol->yobidasi, assign | StringLine::FLAG_COPY_STRVAR, rhs.value));

			}
		}
		
		return std::any();
	}


	// for assigning string literals
	std::any visitStringAssign(woditextParser::StringAssignContext* ctx) override {

		std::string original = ctx->STRING()->getText();
		std::string dequoted = original.substr(1, original.size() - 2);
		// assign to db
		if (woditextParser::DbaccessContext* dbctx = ctx->lhs()->dbaccess()) {
			WodNumber typenum = eval_safe(dbctx->expr(0));
			if (!typenum.is_ref && typenum.value > 99) error(ctx, "attempted to reference DB typenum greater than 99");
			WodNumber datanum = eval_safe(dbctx->expr(1));
			WodNumber valuenum = eval_safe(dbctx->expr(2));

			DBLine::db_type db;
			if (dbctx->CDB())			db = DBLine::cdb;
			else if (dbctx->SDB())		db = DBLine::sdb;
			else /* UDB */				db = DBLine::udb;

			DBLine::assign_type assign;
			if (ctx->AS_EQ())  assign = DBLine::assign_eq;
			else /* plus eq */ assign = DBLine::assign_plus_eq;

			current_event->append(std::make_unique<DBLine>(
				typenum.value, datanum.value, valuenum.value, assign, dequoted
			));

		}
		// assign to variable
		else {
			std::string varname = ctx->lhs()->ID()->getText();
			if (ctx->lhs()->vartype()) {
				if (ctx->lhs()->vartype()->T_STR()) {
					new_var(varname, t_str);
				}
				else error(ctx, "cannot assign integer literal to string variable");
			}
			VarSymbol* dest_symbol = st.lookup_var(varname);
			if (dest_symbol) {
				// get assignment type
				StringLine::assign_type assign;
				if (ctx->AS_EQ())  assign = StringLine::assign_eq;
				else /* plus eq */ assign = StringLine::assign_plus_eq;

				// assign to var
				current_event->append(std::make_unique<StringLine>(
					dest_symbol->yobidasi, assign, dequoted));
			}
			else error(ctx, "undeclared variable '" + varname + "'");
		}

		return std::any();
	}

	std::any visitCallStmt(woditextParser::CallStmtContext* ctx) override {
		std::string name = ctx->ID()->getText();
		CommonSymbol* symbol = st.lookup_common(name);
		if (symbol) {

			// check if number of args matches
			int numargs = ctx->expr().size();
			if (numargs != symbol->params.size()) error(ctx, "wrong number of params in call");

			int_stack.save_temp();
			// eval args
			std::vector<int32_t> int_args;
			std::vector<int32_t> str_args;
			for (int i = 0; i < numargs; i++) {
				if (symbol->params.at(i) == t_int) {
					int_args.push_back(eval_safe(ctx->expr(i)).value);
				}
				else if (symbol->params.at(i) == t_str) {
					str_args.push_back(eval_safe(ctx->expr(i)).value);
				}
				else error(ctx, "no such basetype");
			}
			int_stack.restore_temp();

			// insert line
			current_event->append(std::make_unique<CallByNameLine>(name, int_args, str_args));
		}
		else error(ctx, "id: lookup for common event " + ctx->ID()->getText() + " failed");
		return std::any();
	}

	std::any visitNumLit(woditextParser::NumLitContext* ctx) override {
		std::string text = ctx->NUM()->getText();
		try {
			return WodNumber(static_cast<int32_t>(stoi(text, 0)));
		}
		catch (const std::out_of_range&) {
			error(ctx, "integer literal " + text + " is too large to fit in a signed 32-bit integer");
		}
		return std::any();
	}

	std::any visitBoolLit(woditextParser::BoolLitContext* ctx) override {
		if (ctx->TRUE()) return WodNumber(1);
		else return WodNumber(0);
	}

	std::any visitDBExpr(woditextParser::DBExprContext* ctx) override {
		WodNumber typenum = eval_safe(ctx->dbaccess()->expr(0));
		if (!typenum.is_ref && typenum.value > 99) error(ctx, "attempted to reference DB typenum greater than 99");
		WodNumber datanum = eval_safe(ctx->dbaccess()->expr(1));
		WodNumber valuenum = eval_safe(ctx->dbaccess()->expr(2));

		DBLine::db_type db;
		if (ctx->dbaccess()->CDB())			db = DBLine::cdb;
		else if (ctx->dbaccess()->SDB())	db = DBLine::sdb;
		else /* UDB */						db = DBLine::udb;

		WodNumber tempvar = new_temp(t_int);
		current_event->append(std::make_unique<DBLine>(
			typenum.value, datanum.value, valuenum.value, 
			db | DBLine::FLAG_ASSIGN_TO_VAR, 
			tempvar.value
		));

		return tempvar;
	}

	std::any visitIdExpr(woditextParser::IdExprContext* ctx) override {
		VarSymbol* symbol = st.lookup_var(ctx->ID()->getText());
		if (symbol) return WodNumber(symbol->yobidasi, true);
		else error(ctx, "id: lookup for symbol " + ctx->ID()->getText() + " failed");
		return std::any();
	}

	std::any visitCallExpr(woditextParser::CallExprContext* ctx) override {
		std::string name = ctx->ID()->getText();
		CommonSymbol* symbol = st.lookup_common(name);
		if (symbol) {
			
			// check if number of args matches
			int numargs = ctx->expr().size();
			if (numargs != symbol->params.size()) error(ctx, "wrong number of params in call");
			
			int_stack.save_temp();
			// eval args
			std::vector<int32_t> int_args;
			std::vector<int32_t> str_args;
			for (int i = 0; i < numargs; i++) {
				if (symbol->params.at(i) == t_int) {
					int_args.push_back(eval_safe(ctx->expr(i)).value);
				}
				else if (symbol->params.at(i) == t_str) {
					str_args.push_back(eval_safe(ctx->expr(i)).value);
				} else error(ctx, "no such basetype");
			}
			int_stack.restore_temp();

			// insert line
			WodNumber tempvar = new_temp(t_int);
			current_event->append(std::make_unique<CallByNameLine>(name, int_args, str_args, tempvar.value));

			return tempvar;

		}
		else error(ctx, "id: lookup for common event " + ctx->ID()->getText() + " failed");
		return std::any();
	}
	
	std::any visitParenExpr(woditextParser::ParenExprContext* ctx) override {
		return ctx->expr()->accept(this);
	}
	
	std::any visitUnaryMinusExpr(woditextParser::UnaryMinusExprContext* ctx) override {
		int_stack.save_temp();
		WodNumber arg = eval_unsafe(ctx->expr());
		int_stack.restore_temp();

		WodNumber tempvar = new_temp(t_int);
		current_event->append(std::make_unique<ArithLine>(
				tempvar, 0, arg, ArithLine::assign_eq | ArithLine::op_minus));

		return tempvar;
	}
	
	std::any visitBinopExpr(woditextParser::BinopExprContext* ctx) override {
		int_stack.save_temp();
		WodNumber left = eval_unsafe(ctx->expr(0));
		WodNumber right = eval_unsafe(ctx->expr(1));
		int_stack.restore_temp();

		ArithLine::arith_op op = ArithLine::op_plus;
		if		(ctx->OP_PLUS())	op = ArithLine::op_plus;
		else if (ctx->OP_MINUS())	op = ArithLine::op_minus;
		else if (ctx->OP_TIMES())	op = ArithLine::op_times;
		else if (ctx->OP_DIV())		op = ArithLine::op_div;
		else if (ctx->OP_MOD())		op = ArithLine::op_mod;
		else if (ctx->OP_AMP())		op = ArithLine::op_bitand;
		else error(ctx, "no matching op");

		WodNumber tempvar = new_temp(t_int);
		current_event->append(std::make_unique<ArithLine>(
				tempvar, left, right, ArithLine::assign_eq | op));
		
		return tempvar;
	}
	
	std::any visitLogicalNotExpr(woditextParser::LogicalNotExprContext* ctx) override {
		int_stack.save_temp();
		WodNumber arg = eval_unsafe(ctx->expr());
		int_stack.restore_temp();


		std::unique_ptr<IntIfHeadLine> headline = std::make_unique<IntIfHeadLine>(arg, 0, IntIfHeadLine::op_neq);
		headline->set_else_branch(true);

		current_event->append(std::move(headline));
		WodNumber tempvar = new_temp(t_int);

		current_event->append(std::make_unique<BranchLine>(1));
		current_event->append(std::make_unique<ArithLine>(
			tempvar, 0, 0, ArithLine::assign_eq | ArithLine::op_plus));

		current_event->append(std::make_unique<ElseBranchLine>());
		current_event->append(std::make_unique<ArithLine>(
			tempvar, 1, 0, ArithLine::assign_eq | ArithLine::op_plus));

		current_event->append(std::make_unique<EndBranchLine>());
		return tempvar;
	}

	std::any visitBinopRelExpr(woditextParser::BinopRelExprContext* ctx) override {
		int_stack.save_temp();
		WodNumber left = eval_unsafe(ctx->expr(0));
		WodNumber right = eval_unsafe(ctx->expr(1));
		int_stack.restore_temp();

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
		WodNumber tempvar = new_temp(t_int);
		
		current_event->append(std::make_unique<BranchLine>(1));
		current_event->append(std::make_unique<ArithLine>(
				tempvar, 1, 0, ArithLine::assign_eq | ArithLine::op_plus));

		current_event->append(std::make_unique<ElseBranchLine>());
		current_event->append(std::make_unique<ArithLine>(
			tempvar, 0, 0, ArithLine::assign_eq | ArithLine::op_plus));

		current_event->append(std::make_unique<EndBranchLine>());
		return tempvar;
	}

	std::any visitDecl(woditextParser::DeclContext* ctx) override {
		std::string varname = ctx->ID()->getText();
		if (ctx->vartype()->T_INT()) new_var(varname, t_int);
		else /* string type */		 new_var(varname, t_str);

		return std::any();
	}
};