/**
* Builds a SymbolTable for the code generator.
*/

#pragma once

#include "antlr4-runtime.h"
#include "woditextBaseVisitor.h"
#include "symboltable.hpp"
#include "commonfile.hpp"
#include "commonevent.hpp"
#include "doublestack.hpp"

class TypeChecker : public woditextBaseVisitor {
private:
	static const int INT_VAR_STACK_START = 10;
	static const int INT_TEMP_STACK_START = 98;
	static const int STR_VAR_STACK_START = 5;
	static const int STR_TEMP_STACK_START = 8;

	// max params per type
	static const int MAX_PARAM_COUNT = 5;

	// Where the engine begins to interpret integers as local references.
	static const int32_t CSELF_YOBIDASI = 1600000;

    SymbolTable* st;
	wod_type current_return_type = t_void;

	DoubleStack int_stack = DoubleStack(INT_VAR_STACK_START, INT_TEMP_STACK_START);
	DoubleStack str_stack = DoubleStack(STR_VAR_STACK_START, STR_TEMP_STACK_START);

	void error(antlr4::ParserRuleContext* ctx, std::string message) const {
		std::cout
			<< "ERROR:  " << message << std::endl
			<< "line:   " << ctx->getStart()->getLine() << std::endl
			<< "col:    " << ctx->getStart()->getCharPositionInLine() << std::endl;
		exit(1);
	}
	
	bool may_be_int(wod_type wt) {
		if (wt == t_int || wt == t_dbunknown) return true;
		else return false;
	}

	bool may_be_str(wod_type wt) {
		if (wt == t_str || wt == t_strlit || wt == t_dbunknown) return true;
		else return false;
	}

public:
    TypeChecker(SymbolTable* st) : st(st) {}

	std::any visitCommon(woditextParser::CommonContext* ctx) override {
		// reset state
		int_stack = DoubleStack(INT_VAR_STACK_START, INT_TEMP_STACK_START);
		str_stack = DoubleStack(STR_VAR_STACK_START, STR_TEMP_STACK_START);

		// name
		std::string common_name = ctx->ID()->getText();

		// handle return type
		if (ctx->returntype()->T_VOID()) current_return_type = t_void;
		else if (ctx->returntype()->T_INT()) current_return_type = t_int;
		else if (ctx->returntype()->T_STR()) current_return_type = t_str;
		else { error(ctx, "unknown return type"); return t_error; }

		// handle params
		int num_int_params = 0;
		int num_str_params = 0;
		std::vector<wod_type> param_types;
		std::vector<woditextParser::ParamContext*> params = ctx->param();
		for (auto iter = params.begin(); iter != params.end(); iter++) {
			std::string param_name = (*iter)->ID()->getText();
			if ((*iter)->vartype()->T_INT()) {
				if (num_int_params > MAX_PARAM_COUNT)
					error(ctx, "too many int parameters in common definition");
				st->insert(param_name, VarSymbol(CSELF_YOBIDASI + num_int_params, num_int_params, t_int));
				param_types.push_back(t_int);
				num_int_params++;
			}
			else if ((*iter)->vartype()->T_STR()) {
				if (num_str_params > MAX_PARAM_COUNT)
					error(ctx, "too many str parameters in common definition");
				st->insert(param_name, VarSymbol(CSELF_YOBIDASI + num_str_params, num_str_params, t_str));
				param_types.push_back(t_str);
				// for strings, param space is the same as variable space, so add new var here to reflect that
				str_stack.push_var();
				num_str_params++;
			}
			else {
				error(ctx, "unexpected param type");
			}
		}

		// make common event symbol
		CommonSymbol csym(current_return_type, param_types);
		st->insert(common_name, csym);

		// visit code
		ctx->codeblock()->accept(this);
	
		return t_error;
	}

	std::any visitCodeblock(woditextParser::CodeblockContext* ctx) override {
		st->open_scope();
		visitChildren(ctx);
		st->close_scope();
		return t_error;
	}

	std::any visitIfstmt(woditextParser::IfstmtContext* ctx) override {
		st->open_scope();
		wod_type wt = std::any_cast<wod_type>(ctx->expr()->accept(this));
		if (!may_be_int(wt)) error(ctx, "invalid boolean condition");
		ctx->stmt(0)->accept(this);
		st->close_scope();

		if (ctx->stmt(1)) {
			st->open_scope();
			ctx->stmt(1)->accept(this);
			st->close_scope();
		}
		return t_error;
	}

	std::any visitForeverLoop(woditextParser::ForeverLoopContext* ctx) override {
		st->open_scope();
		ctx->stmt()->accept(this);
		st->close_scope();
		return t_error;
	}

	std::any visitCountLoop(woditextParser::CountLoopContext* ctx) override {
		st->open_scope();
		wod_type wt = std::any_cast<wod_type>(ctx->expr()->accept(this));
		if (!may_be_int(wt)) error(ctx, "loop count is not a number");
		ctx->stmt()->accept(this);
		st->close_scope();
		return t_error;
	}

	std::any visitWhileLoop(woditextParser::WhileLoopContext* ctx) override {
		st->open_scope();
		wod_type wt = std::any_cast<wod_type>(ctx->expr()->accept(this));
		if (!may_be_int(wt)) error(ctx, "loop count is not a valid boolean condition");
		ctx->stmt()->accept(this);
		st->close_scope();
		return t_error;
	}

	std::any visitAssign(woditextParser::AssignContext* ctx) override {
		wod_type lhs_wt = std::any_cast<wod_type>(ctx->lhs()->accept(this));
		wod_type expr_wt = std::any_cast<wod_type>(ctx->expr()->accept(this));
		if (lhs_wt == t_void || expr_wt == t_void || lhs_wt == t_error || expr_wt == t_error) {
			error(ctx, "unexpected assignment types");
		}
		else if (lhs_wt == t_int && expr_wt == t_strlit) {
			error(ctx, "tried to assign string literal to integer");
		}
		else if (lhs_wt == t_str && expr_wt == t_int) {
			error(ctx, "tried to assign integer expression to string");
		}
		return t_error;
	}

	std::any visitReturn(woditextParser::ReturnContext* ctx) override {
		// if return is empty, then function should return void
		if (!ctx->expr()) {
			if (current_return_type != t_void) {
				error(ctx, "returned non-void in void-returning common");
			}
			return t_error;
		}

		// otherwise, compare return type with expr type
		wod_type expr_type = std::any_cast<wod_type>(ctx->expr()->accept(this));
		if (!(current_return_type == t_int && may_be_int(expr_type))
			&& !(current_return_type == t_str && may_be_str(expr_type))) {
			error(ctx, "type of returned value is different from common event return type");
		}
		return t_error;
	}

	/*
	*	THINGS THAT PRODUCE TYPES (but don't have them)
	*/

	std::any visitLhs(woditextParser::LhsContext* ctx) override {
		wod_type wt;
		if (ctx->decl()) wt = std::any_cast<wod_type>(ctx->decl()->accept(this));
		else if (ctx->var()) wt = std::any_cast<wod_type>(ctx->var()->accept(this));
		else if (ctx->dbaccess()) wt = std::any_cast<wod_type>(ctx->dbaccess()->accept(this));
		else wt = t_error;
		return wt;
	}

	std::any visitDecl(woditextParser::DeclContext* ctx) override {
		std::string varname = ctx->ID()->getText();
		wod_type wt;
		if (ctx->vartype()->T_INT()) wt = t_int;
		else if (ctx->vartype()->T_STR()) wt = t_str;
		else { error(ctx, "unexpected decl type"); return t_error; }

		int stackpos;
		if (wt == t_int) stackpos = int_stack.push_var();
		else /* string */ stackpos = str_stack.push_var();

		VarSymbol sym = VarSymbol(CSELF_YOBIDASI + stackpos, stackpos, wt);
		if (!st->insert(varname, sym)) error(ctx, "duplicate declaration of " + varname);

		return wt;
	}

	std::any visitVar(woditextParser::VarContext* ctx) override {
		VarSymbol* sym = st->lookup_var(ctx->ID()->getText());
		if (!sym) { error(ctx, "undefined variable"); return t_error; }

		return sym->type;
	}

	std::any visitDbaccess(woditextParser::DbaccessContext* ctx) override {
		// if a db access parameter is a string, it must be a string literal:
		// string variables _can_ be put into the slot, but they won't work properly in the engine
		// in particular, it seems like they're automatically replaced with just 0

		auto checkparam = [this](woditextParser::ExprContext* ctx) {
			wod_type wt = std::any_cast<wod_type>(ctx->accept(this));
			if (wt != t_int && wt != t_strlit) {
				error(ctx, "invalid db access (maybe tried to use string variable in DB access parameter?)");
			}
		};

		checkparam(ctx->expr(0));
		checkparam(ctx->expr(1));
		checkparam(ctx->expr(2));

		// as the compiler doesn't know the DB layout, it doesn't know the type of the db access
		return t_dbunknown;
	}

	std::any visitCall(woditextParser::CallContext* ctx) override {
		// check symbol exists
		CommonSymbol* sym = st->lookup_common(ctx->ID()->getText());
		if (!sym) { error(ctx, "undefined common"); return t_error; }

		// check arg count
		int numargs = ctx->expr().size();
		if (numargs != sym->params.size()) error(ctx, "wrong number of params in call");

		// check arg types
		std::vector<int32_t> int_args;
		std::vector<num_or_str> str_args;
		for (int i = 0; i < numargs; i++) {
			wod_type arg_type = std::any_cast<wod_type>(ctx->expr(i)->accept(this));
			if (sym->params.at(i) == t_int) {
				if (!may_be_int(arg_type))
					error(ctx, "call argument type mismatch");
			}
			else if (sym->params.at(i) == t_str) {
				if (!may_be_str(arg_type))
					error(ctx, "call argument type mismatch");
			}
			// parameter should not be anything other than int or str
			else error(ctx, "unexpected parameter type");
		}

		return sym->return_type;
	}

	/*
	*	EXPRESSIONS (nodes that have a type)
	*/

	std::any visitCallExpr(woditextParser::CallExprContext* ctx) override {
		wod_type wt = std::any_cast<wod_type>(ctx->call()->accept(this));
		ctx->wt = wt;
		return wt;
	}

	std::any visitDBExpr(woditextParser::DBExprContext* ctx) override {
		wod_type wt = std::any_cast<wod_type>(ctx->dbaccess()->accept(this));
		ctx->wt = wt;
		return wt;
	}

	std::any visitUnaryMinusExpr(woditextParser::UnaryMinusExprContext* ctx) override {
		wod_type expr_type = std::any_cast<wod_type>(ctx->expr()->accept(this));
		if (may_be_int(expr_type)) {
			ctx->wt = t_int;
			return t_int;
		}
		else {
			error(ctx, "tried to negate non-integer value");
			return t_error;
		}
	}

	std::any visitLogicalNotExpr(woditextParser::LogicalNotExprContext* ctx) override {
		wod_type expr_type = std::any_cast<wod_type>(ctx->expr()->accept(this));
		if (may_be_int(expr_type)) {
			ctx->wt = t_int;
			return t_int;
		}
		else {
			error(ctx, "tried to (logical) negate non-integer value");
			return t_error;
		}
	}

	std::any visitBinopExpr(woditextParser::BinopExprContext* ctx) override {
		wod_type expr1_type = std::any_cast<wod_type>(ctx->expr(0)->accept(this));
		wod_type expr2_type = std::any_cast<wod_type>(ctx->expr(1)->accept(this));
		if (may_be_int(expr1_type) && may_be_int(expr2_type)) {
			ctx->wt = t_int;
			return t_int;
		}
		else {
			error(ctx, "binary expression with non-integer types");
			return t_error;
		}
	}

	std::any visitBinopRelExpr(woditextParser::BinopRelExprContext* ctx) override {
		wod_type expr1_type = std::any_cast<wod_type>(ctx->expr(0)->accept(this));
		wod_type expr2_type = std::any_cast<wod_type>(ctx->expr(1)->accept(this));
		if (may_be_int(expr1_type) && may_be_int(expr2_type)) {
			ctx->wt = t_int;
			return t_int;
		}
		else {
			error(ctx, "binary expression with non-integer types");
			return t_error;
		}
	}

	std::any visitBinopRelEqExpr(woditextParser::BinopRelEqExprContext* ctx) override {
		wod_type expr1_type = std::any_cast<wod_type>(ctx->expr(0)->accept(this));
		wod_type expr2_type = std::any_cast<wod_type>(ctx->expr(1)->accept(this));
		if (may_be_int(expr1_type) && may_be_int(expr2_type)) {
			ctx->wt = t_int;
			return t_int;
		}
		else if (may_be_str(expr1_type) && may_be_str(expr2_type)) {
			ctx->wt = t_int;
			return t_int;
		}
		else {
			error(ctx, "equality comparison with mismatched types");
			return t_error;
		}
	}

	std::any visitParenExpr(woditextParser::ParenExprContext* ctx) override {
		wod_type wt = std::any_cast<wod_type>(ctx->expr()->accept(this));
		ctx->wt = wt;
		return wt;
	}

	std::any visitVarExpr(woditextParser::VarExprContext* ctx) override {
		wod_type wt = std::any_cast<wod_type>(ctx->var()->accept(this));
		ctx->wt = wt;
		return wt;
	}

	std::any visitNumLit(woditextParser::NumLitContext* ctx) override {
		ctx->wt = t_int;
		return t_int;
	}

	std::any visitBoolLit(woditextParser::BoolLitContext* ctx) override {
		ctx->wt = t_int;
		return t_int;
	}

	std::any visitStringLit(woditextParser::StringLitContext* ctx) override {
		ctx->wt = t_strlit;
		return t_strlit;
	}

};