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
	static const int32_t YOBIDASI_THRESHOLD = 1000000;
	static const int32_t CSELF_YOBIDASI = 1600000;

	CommonEvent* current_event;
	int var_stackpos = VAR_STACK_START;
	int temp_stackpos = TEMP_STACK_START;
	int lowest_temp_stackpos = TEMP_STACK_START;
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

	int32_t new_var() {
		if (var_stackpos >= lowest_temp_stackpos) {
			error("no more space for variables");
		}
		int32_t var_csid = CSELF_YOBIDASI + var_stackpos;
		var_stackpos++;
		return var_csid;
	}

	int32_t new_temp() {
		if (temp_stackpos <= var_stackpos) {
			error("no more space for temp variables");
		}
		int32_t temp_csid = CSELF_YOBIDASI + temp_stackpos;
		current_event->cself_names.at(temp_stackpos) = "__t" + std::to_string(temp_stackpos);
		temp_stackpos--;
		lowest_temp_stackpos--;
		return temp_csid;
	}

public:
	CommonFile cf;

	std::any visitCommon(woditextParser::CommonContext* ctx) override {
		var_stackpos = VAR_STACK_START;
		temp_stackpos = TEMP_STACK_START;
		lowest_temp_stackpos = TEMP_STACK_START;
		st = SymbolTable();

		current_event = new CommonEvent;
		cf.add_common(current_event);

		current_event->name = ctx->ID()->getText();
		visitChildren(ctx);

		return std::any();
	}

	std::any visitAssign(woditextParser::AssignContext* ctx) override {
		int saved_temp_pos = temp_stackpos;
		
		std::string varname = ctx->lhs()->ID()->getText();

		int32_t rhs = std::any_cast<int32_t>(ctx->expr()->accept(this));

		// replace the temp destination of the most recent arith operation to point to varname's cself
        if (current_event->lines.size() <= 0) error(ctx, "assign: linecount assertion failed");

		ArithLine* prev_line = dynamic_cast<ArithLine*>(current_event->lines.back());
		if (prev_line) {
			prev_line->dest = st.lookup(varname)->yobidasi;

			// update assignment operator
			if (ctx->AS_PEQ()) prev_line->assign = ArithLine::assign_plus_eq;
			else if (ctx->AS_MEQ()) prev_line->assign = ArithLine::assign_minus_eq;
			else if (ctx->AS_TEQ()) prev_line->assign = ArithLine::assign_times_eq;
			else if (ctx->AS_DEQ()) prev_line->assign = ArithLine::assign_div_eq;
		} else { error(ctx, "assign: arith assertion failed"); }

        // restore temp stack
		temp_stackpos = saved_temp_pos;
		return std::any();
	}

	std::any visitNumExpr(woditextParser::NumExprContext* ctx) override {
		return static_cast<int32_t>(stoi(ctx->NUM()->getText()));
	}

	std::any visitIdExpr(woditextParser::IdExprContext* ctx) override {
		int32_t cself = st.lookup(ctx->ID()->getText())->yobidasi;
		if (cself < 0) exit(1);
		return cself;
	}
	
	std::any visitParenExpr(woditextParser::ParenExprContext* ctx) override {
		return ctx->expr()->accept(this);
	}
	
	/**
	* Negates expr (since that is the only unop)
	* @return	yobidasi of the cself in which the negated result is stored
	*/
	std::any visitUnopExpr(woditextParser::UnopExprContext* ctx) override {
		int32_t arg = std::any_cast<int32_t>(ctx->expr()->accept(this));
		
		int32_t temp_var = new_temp();
        current_event->append(new ArithLine(temp_var, 0, arg, ArithLine::assign_eq, ArithLine::op_minus));

		return temp_var;
	}
	
	/**
	* @return	yobidasi of the cself in which the result is stored
	*/
	std::any visitBinopExpr(woditextParser::BinopExprContext* ctx) override {
		int32_t arg0 = std::any_cast<int32_t>(ctx->expr(0)->accept(this));
		int32_t arg1 = std::any_cast<int32_t>(ctx->expr(1)->accept(this));

		int32_t temp_var = new_temp();
		ArithLine::arith_op op = ArithLine::op_plus;
		if		(ctx->OP_PLUS())	op = ArithLine::op_plus;
		else if (ctx->OP_MINUS())	op = ArithLine::op_minus;
		else if (ctx->OP_TIMES())	op = ArithLine::op_times;
		else if (ctx->OP_DIV())		op = ArithLine::op_div;
		else if (ctx->OP_MOD())		op = ArithLine::op_mod;
		else error(ctx, "no matching op");

		current_event->append(new ArithLine(temp_var, arg0, arg1, ArithLine::assign_eq, op));
		
		return temp_var;
	}

	std::any visitDecl(woditextParser::DeclContext* ctx) override {
		// create variable
		if (var_stackpos >= lowest_temp_stackpos || var_stackpos >= current_event->MAX_NUM_CSELF_NAMES) {
			error(ctx, "no more cself space for variables");
		}
		
		std::string varname = ctx->ID()->getText();

		VarSymbol new_symbol = VarSymbol(varname, var_stackpos + CSELF_YOBIDASI, t_int);
		if (!st.insert(new_symbol)) {
			error(ctx, "redeclaration of variable " + varname);
		}

		current_event->cself_names.at(var_stackpos) = ctx->ID()->getText();
		return var_stackpos++;
	}
};