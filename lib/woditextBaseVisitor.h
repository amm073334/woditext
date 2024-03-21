
// Generated from woditext.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "woditextVisitor.h"


/**
 * This class provides an empty implementation of woditextVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  woditextBaseVisitor : public woditextVisitor {
public:

  virtual std::any visitCommonlist(woditextParser::CommonlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommon(woditextParser::CommonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParams(woditextParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamlist(woditextParser::ParamlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(woditextParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCodeblock(woditextParser::CodeblockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfstmt(woditextParser::IfstmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturntype(woditextParser::ReturntypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVartype(woditextParser::VartypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoopstmt(woditextParser::LoopstmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(woditextParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl(woditextParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(woditextParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreak(woditextParser::BreakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn(woditextParser::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp(woditextParser::CompContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall(woditextParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgs(woditextParser::ArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArglist(woditextParser::ArglistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLhs(woditextParser::LhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDbaccess(woditextParser::DbaccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDbattr(woditextParser::DbattrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdExpr(woditextParser::IdExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumExpr(woditextParser::NumExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnopExpr(woditextParser::UnopExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallExpr(woditextParser::CallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenExpr(woditextParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinopExpr(woditextParser::BinopExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

