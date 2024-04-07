/**
 * Given a symbol table and modified AST generated by the typechecker, generates the actual common file.
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
	static const int STR_VAR_STACK_START = 5;
	static const int STR_TEMP_STACK_START = 8;
	
	static const int INT_RETURN_INDEX = 99;
	static const int STR_RETURN_INDEX = 9;

	// Where the engine begins to interpret integers as local references.
	static const int32_t CSELF_YOBIDASI = 1600000;

	CommonEvent* current_event = nullptr;

	DoubleStack int_stack = DoubleStack(INT_VAR_STACK_START, INT_TEMP_STACK_START);
	DoubleStack str_stack = DoubleStack(STR_VAR_STACK_START, STR_TEMP_STACK_START);
	
	SymbolTable* st;

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
	* Get new temporary.
	* @param ty	Type of the temporary.
	* @return	WodNumber value of the temporary.
	*/
	WodNumber new_temp(wod_type ty) {
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

	std::tuple<WodNumber, WodNumber>
	eval_binop(woditextParser::ExprContext* ctx1, woditextParser::ExprContext* ctx2) {
		try {
			int_stack.save_temp();
			WodNumber result1 = std::any_cast<WodNumber>(ctx1->accept(this));
			if (result1.should_suppress_yobidasi()) {
				WodNumber t = new_temp(t_int);
				current_event->append(std::make_unique<ArithLine>(t, result1.value, 0, ArithLine::af_yobanai1));
				result1 = t;
			}

			WodNumber result2 = std::any_cast<WodNumber>(ctx1->accept(this));
			if (result2.should_suppress_yobidasi()) {
				WodNumber t = new_temp(t_int);
				current_event->append(std::make_unique<ArithLine>(t, result1.value, 0, ArithLine::af_yobanai1));
				result2 = t;
			}
			int_stack.restore_temp();
			return {result1, result2};
		}
		catch (const std::bad_any_cast&) {
			assert(false);
		}
	}

	/**
	* Evaluate db access parameters.
	* @ctx		Context of Dbaccess node.
	* @return	Tuple of variants that are either numbers or string identifiers.
	*/
	std::tuple<num_or_str, num_or_str, num_or_str>
	eval_dbaccess(woditextParser::DbaccessContext* ctx) {

		woditextParser::ExprContext* ec;
		std::variant<int32_t, std::string> type, data, value;

		ec = ctx->expr(0);
		if (ec->wt == t_strlit) type = trim(ec->getText());
		else type = eval_safe(ec).value;
		ec = ctx->expr(1);
		if (ec->wt == t_strlit) data = trim(ec->getText());
		else data = eval_safe(ec).value;
		ec = ctx->expr(2);
		if (ec->wt == t_strlit) value = trim(ec->getText());
		else value = eval_safe(ec).value;

		return {type, data, value};
	}

	std::string trim(std::string in) {
		return in.substr(1, in.size() - 2);
	}

public:
	CommonFile cf;

	CommonGen(SymbolTable* st) : st(st) {}

	std::any visitCommon(woditextParser::CommonContext* ctx) override {
		// reset state
		int_stack = DoubleStack(INT_VAR_STACK_START, INT_TEMP_STACK_START);
		str_stack = DoubleStack(STR_VAR_STACK_START, STR_TEMP_STACK_START);

		// make new commonevent
		current_event = cf.add_common(std::make_unique<CommonEvent>());

		std::string common_name = ctx->ID()->getText();

		CommonSymbol* csym = st->lookup_common(common_name);
		if (csym->return_type == t_int)
			current_event->return_cself_id = INT_RETURN_INDEX;
		else if (csym->return_type == t_str)
			current_event->return_cself_id = STR_RETURN_INDEX;
		else error(ctx, "panic");

		// handle params
		for (auto& p : csym->params) {
			if (p == t_int) current_event->new_int_param("");
			else if (p == t_str) current_event->new_str_param("");
			else error(ctx, "panic");
		}

		// visit code
		bool has_code = std::any_cast<bool>(ctx->codeblock()->accept(this));

		// if a common is completely blank, the engine will determine commonevent.dat as corrupted
		// append an empty line at the end of the common to alleviate this
		if (!has_code) current_event->append(std::make_unique<EmptyLine>());

		return std::any();
	}

	std::any visitCodeblock(woditextParser::CodeblockContext* ctx) override {
		visitChildren(ctx);

		// return a boolean value indicating whether or not the codeblock contained at least one statement
		if (!ctx->stmt(0)) return false;
		else return true;
	}

	std::any visitIfstmt(woditextParser::IfstmtContext* ctx) override {
		int_stack.save_temp();
		WodNumber condition = eval_unsafe(ctx->expr());
		int_stack.restore_temp();

		std::unique_ptr<IntIfHeadLine> headline
			= std::make_unique<IntIfHeadLine>(condition, 0, IntIfHeadLine::op_neq);
		
		bool has_else = ctx->stmt(1);
		if (has_else) headline->set_else_branch(true);
		
		current_event->append(std::move(headline));
		current_event->append(std::make_unique<BranchLine>(1));
		
		ctx->stmt(0)->accept(this);

		if (has_else) {
			current_event->append(std::make_unique<ElseBranchLine>());
			ctx->stmt(1)->accept(this);
		}

		current_event->append(std::make_unique<EndBranchLine>());

		return std::any();
	}

	std::any visitForeverLoop(woditextParser::ForeverLoopContext* ctx) override {
		current_event->append(std::make_unique<LoopForeverHeadLine>());
		ctx->stmt()->accept(this);
		current_event->append(std::make_unique<LoopEndLine>());
		return std::any();
	}

	std::any visitCountLoop(woditextParser::CountLoopContext* ctx) override {
		int_stack.save_temp();
		// this command does not support disabling variable references; do safe eval
		WodNumber arg = eval_safe(ctx->expr());
		int_stack.restore_temp();

		current_event->append(std::make_unique<LoopCountHeadLine>(arg.value));
		ctx->stmt()->accept(this);
		current_event->append(std::make_unique<LoopEndLine>());
		return std::any();
	}

	std::any visitWhileLoop(woditextParser::WhileLoopContext* ctx) override {
		// STUB
		return visitChildren(ctx);
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
			int_stack.save_temp();
			auto [type, data, value] = eval_dbaccess(dbctx);

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
			WodNumber rhs = eval_safe(ctx->expr());

			current_event->append(std::make_unique<DBLine>(
				type, data, value, assign, rhs.value
			));
			int_stack.restore_temp();

			return std::any();
		} 

		// else, assign to variable
		VarSymbol* sym;
		if (ctx->lhs()->decl()) 
			sym = ctx->lhs()->decl()->vs;
		else sym = ctx->lhs()->var()->vs;
		assert(sym);

		wod_type expr_type = ctx->expr()->wt;

		if (expr_type == t_int) {
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
					WodNumber(sym->yobidasi, true), rhs, 0, assign));
		}
		else if (expr_type == t_str) {

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
				sym->yobidasi, assign | StringLine::FLAG_COPY_STRVAR, rhs.value));

		}
		else if (expr_type == t_strlit) {
			StringLine::assign_type assign;
			if (ctx->AS_EQ())  assign = StringLine::assign_eq;
			else if (ctx->AS_PEQ()) assign = StringLine::assign_plus_eq;
			else {
				error(ctx, "cannot use this assignment operator when assigning to a string variable");
				return std::any();
			}

			current_event->append(std::make_unique<StringLine>(
				sym->yobidasi, assign, trim(ctx->expr()->getText())));
		}
		
		return std::any();
	}

	std::any visitReturn(woditextParser::ReturnContext* ctx) override {
		wod_type curr_return_type = st->lookup_common(current_event->name)->return_type;

		// if return is empty, then function should return void
		if (!ctx->expr()) {
			current_event->append(std::make_unique<ReturnLine>());
		}
	
		wod_type expr_type = ctx->expr()->wt;
		// otherwise, compare return type with expr type
		if (expr_type == t_int) {
			// integer
			int_stack.save_temp();
			WodNumber rhs = eval_unsafe(ctx->expr());
			int_stack.restore_temp();
			current_event->append(std::make_unique<ArithLine>(
				CSELF_YOBIDASI + INT_RETURN_INDEX, rhs, 0, 0));
		}
		else if (expr_type == t_str) {
			// string
			int_stack.save_temp();
			WodNumber rhs = eval_unsafe(ctx->expr());
			int_stack.restore_temp();
			current_event->append(std::make_unique<StringLine>(
				CSELF_YOBIDASI + STR_RETURN_INDEX, StringLine::FLAG_COPY_STRVAR, rhs.value));
		}
		else if (expr_type == t_strlit) {
			current_event->append(std::make_unique<StringLine>(
				CSELF_YOBIDASI + STR_RETURN_INDEX, StringLine::FLAG_COPY_STRVAR, trim(ctx->expr()->getText())));
		}
		current_event->append(std::make_unique<ReturnLine>());

		return std::any();
	}

	std::any visitNumLit(woditextParser::NumLitContext* ctx) override {
		std::string text = ctx->NUM()->getText();
		try {
			return WodNumber(static_cast<int32_t>(stoi(text, nullptr, 0)));
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
		woditextParser::DbaccessContext* dbctx = ctx->dbaccess();

		int_stack.save_temp();
		auto [type, data, value] = eval_dbaccess(dbctx);
		int_stack.restore_temp();

		DBLine::db_type db;
		if (ctx->dbaccess()->CDB())			db = DBLine::cdb;
		else if (ctx->dbaccess()->SDB())	db = DBLine::sdb;
		else /* UDB */						db = DBLine::udb;

		// NB: DB access used in an expression is assumed to retrieve an integer
		// as the compiler doesn't know the DB layout, it doesn't error when a string is retrieved instead
		// (but this will cause a runtime error)
		WodNumber tempvar = new_temp(t_int);
		current_event->append(std::make_unique<DBLine>(
			type, data, value, 
			db | DBLine::FLAG_ASSIGN_TO_VAR, 
			tempvar.value
		));

		return tempvar;
	}

	std::any visitVarExpr(woditextParser::VarExprContext* ctx) override {
		return ctx->var()->accept(this);
	}

	std::any visitCallExpr(woditextParser::CallExprContext* ctx) override {
		CommonSymbol* symbol = ctx->call()->cs;
			
		int numargs = ctx->call()->expr().size();
		int_stack.save_temp();
		// eval args
		std::vector<int32_t> int_args;
		std::vector<num_or_str> str_args;
		for (int i = 0; i < numargs; i++) {
			if (symbol->params.at(i) == t_int) {
				int_args.push_back(eval_safe(ctx->call()->expr(i)).value);
			}
			else if (symbol->params.at(i) == t_str) {
				if (ctx->call()->expr(i)->wt == t_str)
					str_args.push_back(eval_safe(ctx->call()->expr(i)).value);
				else str_args.push_back(trim(ctx->call()->expr(i)->getText()));
			} else error(ctx, "no such basetype");
		}
		int_stack.restore_temp();

		// insert line
		WodNumber tempvar = new_temp(t_int);
		current_event->append(std::make_unique<CallByNameLine>(
			ctx->call()->ID()->getText(), int_args, str_args, tempvar.value));

		return tempvar;

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

	std::any visitBinopRelEqExpr(woditextParser::BinopRelEqExprContext* ctx) override {
		if (ctx->expr(0)->wt == t_int) {
			// integer compare
			int_stack.save_temp();
			WodNumber left = eval_unsafe(ctx->expr(0));
			WodNumber right = eval_unsafe(ctx->expr(1));
			int_stack.restore_temp();

			IntIfHeadLine::comp_op op = IntIfHeadLine::op_gt;
			if (ctx->OP_EQ()) op = IntIfHeadLine::op_eq;
			else if (ctx->OP_NEQ()) op = IntIfHeadLine::op_neq;
			else error(ctx, "panic");

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
		else {
			// string compare
			// TODO
			return std::any();
		}
	}

};