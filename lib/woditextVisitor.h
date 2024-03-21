
// Generated from woditext.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "woditextParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by woditextParser.
 */
class  woditextVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by woditextParser.
   */
    virtual std::any visitCommonlist(woditextParser::CommonlistContext *context) = 0;

    virtual std::any visitCommon(woditextParser::CommonContext *context) = 0;

    virtual std::any visitParams(woditextParser::ParamsContext *context) = 0;

    virtual std::any visitParamlist(woditextParser::ParamlistContext *context) = 0;

    virtual std::any visitParam(woditextParser::ParamContext *context) = 0;

    virtual std::any visitCodeblock(woditextParser::CodeblockContext *context) = 0;

    virtual std::any visitIfstmt(woditextParser::IfstmtContext *context) = 0;

    virtual std::any visitReturntype(woditextParser::ReturntypeContext *context) = 0;

    virtual std::any visitVartype(woditextParser::VartypeContext *context) = 0;

    virtual std::any visitLoopstmt(woditextParser::LoopstmtContext *context) = 0;

    virtual std::any visitStmt(woditextParser::StmtContext *context) = 0;

    virtual std::any visitDecl(woditextParser::DeclContext *context) = 0;

    virtual std::any visitAssign(woditextParser::AssignContext *context) = 0;

    virtual std::any visitBreak(woditextParser::BreakContext *context) = 0;

    virtual std::any visitReturn(woditextParser::ReturnContext *context) = 0;

    virtual std::any visitComp(woditextParser::CompContext *context) = 0;

    virtual std::any visitCall(woditextParser::CallContext *context) = 0;

    virtual std::any visitArgs(woditextParser::ArgsContext *context) = 0;

    virtual std::any visitArglist(woditextParser::ArglistContext *context) = 0;

    virtual std::any visitLhs(woditextParser::LhsContext *context) = 0;

    virtual std::any visitDbaccess(woditextParser::DbaccessContext *context) = 0;

    virtual std::any visitDbattr(woditextParser::DbattrContext *context) = 0;

    virtual std::any visitIdExpr(woditextParser::IdExprContext *context) = 0;

    virtual std::any visitNumExpr(woditextParser::NumExprContext *context) = 0;

    virtual std::any visitUnopExpr(woditextParser::UnopExprContext *context) = 0;

    virtual std::any visitCallExpr(woditextParser::CallExprContext *context) = 0;

    virtual std::any visitParenExpr(woditextParser::ParenExprContext *context) = 0;

    virtual std::any visitBinopExpr(woditextParser::BinopExprContext *context) = 0;


};

