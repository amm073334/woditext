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

	static const int INT_RETURN_INDEX = 99;
	static const int STR_RETURN_INDEX = 9;

	static const int MAX_PARAM_COUNT = 5;

	// Where the engine begins to interpret integers as local references.
	static const int32_t CSELF_YOBIDASI = 1600000;

	CommonFile* cf;
    SymbolTable* st;

	DoubleStack int_stack = DoubleStack(INT_VAR_STACK_START, INT_TEMP_STACK_START);
	DoubleStack str_stack = DoubleStack(STR_VAR_STACK_START, STR_TEMP_STACK_START);

	void error(antlr4::ParserRuleContext* ctx, std::string message) const {
		std::cout
			<< "ERROR:  " << message << std::endl
			<< "line:   " << ctx->getStart()->getLine() << std::endl
			<< "col:    " << ctx->getStart()->getCharPositionInLine() << std::endl;
		exit(1);
	}
	
public:
    TypeChecker(CommonFile* cf, SymbolTable* st) : cf(cf), st(st) {}

	std::any visitCommon(woditextParser::CommonContext* ctx) override {
		// reset state
		int_stack = DoubleStack(INT_VAR_STACK_START, INT_TEMP_STACK_START);
		str_stack = DoubleStack(STR_VAR_STACK_START, STR_TEMP_STACK_START);

		// make new commonevent
		CommonSymbol csym(cf->add_common(std::make_unique<CommonEvent>()));

		// handle return type
		if (ctx->returntype()->T_VOID()) csym.return_type = t_void;
		else if (ctx->returntype()->T_INT()) csym.return_type = t_int;
		else if (ctx->returntype()->T_STR()) csym.return_type = t_str;
		else error(ctx, "unknown return type");

		// handle params
		int num_int_params = 0;
		int num_str_params = 0;
		std::vector<wod_type> param_types;
		std::vector<woditextParser::ParamContext*> params = ctx->param();
		for (auto iter = params.begin(); iter != params.end(); iter++) {
			std::string name = (*iter)->ID()->getText();
			if ((*iter)->vartype()->T_INT()) {
				if (num_int_params > MAX_PARAM_COUNT)
					error(ctx, "too many int parameters in common definition");
				st->insert(VarSymbol(name, CSELF_YOBIDASI + num_int_params, t_int));
				param_types.push_back(t_int);
				num_int_params++;
			}
			else if ((*iter)->vartype()->T_STR()) {
				if (num_str_params > MAX_PARAM_COUNT)
					error(ctx, "too many str parameters in common definition");
				st->insert(VarSymbol(name, CSELF_YOBIDASI + num_str_params, t_str));
				param_types.push_back(t_str);
				// for strings, param space is the same as variable space, so add new var here to reflect that
				str_stack.push_var();
				num_str_params++;
			}
			else {
				error(ctx, "unexpected param type");
			}
		}

		csym.params = param_types;

		// make common event symbol
		st->insert(csym);

		// visit code
		st->open_scope();
		ctx->codeblock()->accept(this);
		st->close_scope();
	
		return std::any();
	}

	std::any visitDecl(woditextParser::DeclContext* ctx) override {

		std::string varname = ctx->ID()->getText();
		wod_type vt;
		if (ctx->vartype()->T_INT()) vt = t_int;
		else /* string */ vt = t_str;

		int stackpos;
		if (vt == t_int) stackpos = int_stack.push_var();
		else /* string */ stackpos = str_stack.push_var();

		VarSymbol sym = VarSymbol(CSELF_YOBIDASI + stackpos, stackpos, vt);
		if (!st->insert(sym)) error(ctx, "duplicate declaration of " + varname);

		return std::any();
	}

	std::any visitVar(woditextParser::VarContext* ctx) override {
		VarSymbol* sym = st->lookup_var(ctx->ID()->getText());
		if (!sym) { error(ctx, "undefined variable"); return t_error; }

		return sym->type;
	}

	std::any visitCall(woditextParser::CallContext* ctx) override {
		// check symbol exists
		CommonSymbol* sym = st->lookup_common(ctx->ID()->getText());
		if (!sym) { error(ctx, "undefined common"); return t_error; }
		
		// check arg count
		int numargs = ctx->expr_or_str().size();
		if (numargs != sym->params.size()) error(ctx, "wrong number of params in call");

		// check arg types
		std::vector<int32_t> int_args;
		std::vector<num_or_str> str_args;
		for (int i = 0; i < numargs; i++) {
			if (sym->params.at(i) == t_int) {
				if (ctx->expr_or_str(i)->STRING())
					error(ctx, "tried to pass string literal into integer arg");
			}
			else if (sym->params.at(i) == t_str) {
				if (ctx->expr_or_str(i)->expr())
					error(ctx, "tried to pass integer into string arg");
			}
			else error(ctx, "unexpected parameter type");
		}

		return sym->return_type;
	}

	std::any visitDbaccess(woditextParser::DbaccessContext* ctx) override {
		// if a db access parameter is a string, it must be a string literal:
		// string variables _can_ be put into the slot, but they won't work properly in the engine
		// in particular, it seems like they're automatically replaced with just 0

		auto checkparam = [this](woditextParser::Expr_or_strContext* ctx) {
			if (std::any_cast<wod_type>(ctx->accept(this)) == t_str
				&& !ctx->STRING()) {
				error(ctx, "tried to use string variable in DB access parameter");
			}
		};
		
		checkparam(ctx->expr_or_str(0));
		checkparam(ctx->expr_or_str(1));
		checkparam(ctx->expr_or_str(2));

		// as the compiler doesn't know the DB layout, it doesn't know the type of the db access
		return t_dbunknown;
	}
};