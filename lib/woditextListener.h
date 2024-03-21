
// Generated from woditext.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "woditextParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by woditextParser.
 */
class  woditextListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCommonlist(woditextParser::CommonlistContext *ctx) = 0;
  virtual void exitCommonlist(woditextParser::CommonlistContext *ctx) = 0;

  virtual void enterCommon(woditextParser::CommonContext *ctx) = 0;
  virtual void exitCommon(woditextParser::CommonContext *ctx) = 0;

  virtual void enterParams(woditextParser::ParamsContext *ctx) = 0;
  virtual void exitParams(woditextParser::ParamsContext *ctx) = 0;

  virtual void enterParamlist(woditextParser::ParamlistContext *ctx) = 0;
  virtual void exitParamlist(woditextParser::ParamlistContext *ctx) = 0;

  virtual void enterParam(woditextParser::ParamContext *ctx) = 0;
  virtual void exitParam(woditextParser::ParamContext *ctx) = 0;

  virtual void enterCodeblock(woditextParser::CodeblockContext *ctx) = 0;
  virtual void exitCodeblock(woditextParser::CodeblockContext *ctx) = 0;

  virtual void enterIfstmt(woditextParser::IfstmtContext *ctx) = 0;
  virtual void exitIfstmt(woditextParser::IfstmtContext *ctx) = 0;

  virtual void enterReturntype(woditextParser::ReturntypeContext *ctx) = 0;
  virtual void exitReturntype(woditextParser::ReturntypeContext *ctx) = 0;

  virtual void enterVartype(woditextParser::VartypeContext *ctx) = 0;
  virtual void exitVartype(woditextParser::VartypeContext *ctx) = 0;

  virtual void enterLoopstmt(woditextParser::LoopstmtContext *ctx) = 0;
  virtual void exitLoopstmt(woditextParser::LoopstmtContext *ctx) = 0;

  virtual void enterStmt(woditextParser::StmtContext *ctx) = 0;
  virtual void exitStmt(woditextParser::StmtContext *ctx) = 0;

  virtual void enterDecl(woditextParser::DeclContext *ctx) = 0;
  virtual void exitDecl(woditextParser::DeclContext *ctx) = 0;

  virtual void enterAssign(woditextParser::AssignContext *ctx) = 0;
  virtual void exitAssign(woditextParser::AssignContext *ctx) = 0;

  virtual void enterBreak(woditextParser::BreakContext *ctx) = 0;
  virtual void exitBreak(woditextParser::BreakContext *ctx) = 0;

  virtual void enterReturn(woditextParser::ReturnContext *ctx) = 0;
  virtual void exitReturn(woditextParser::ReturnContext *ctx) = 0;

  virtual void enterComp(woditextParser::CompContext *ctx) = 0;
  virtual void exitComp(woditextParser::CompContext *ctx) = 0;

  virtual void enterUnop(woditextParser::UnopContext *ctx) = 0;
  virtual void exitUnop(woditextParser::UnopContext *ctx) = 0;

  virtual void enterCall(woditextParser::CallContext *ctx) = 0;
  virtual void exitCall(woditextParser::CallContext *ctx) = 0;

  virtual void enterArgs(woditextParser::ArgsContext *ctx) = 0;
  virtual void exitArgs(woditextParser::ArgsContext *ctx) = 0;

  virtual void enterArglist(woditextParser::ArglistContext *ctx) = 0;
  virtual void exitArglist(woditextParser::ArglistContext *ctx) = 0;

  virtual void enterLhs(woditextParser::LhsContext *ctx) = 0;
  virtual void exitLhs(woditextParser::LhsContext *ctx) = 0;

  virtual void enterDbaccess(woditextParser::DbaccessContext *ctx) = 0;
  virtual void exitDbaccess(woditextParser::DbaccessContext *ctx) = 0;

  virtual void enterDbattr(woditextParser::DbattrContext *ctx) = 0;
  virtual void exitDbattr(woditextParser::DbattrContext *ctx) = 0;

  virtual void enterIdExpr(woditextParser::IdExprContext *ctx) = 0;
  virtual void exitIdExpr(woditextParser::IdExprContext *ctx) = 0;

  virtual void enterNumExpr(woditextParser::NumExprContext *ctx) = 0;
  virtual void exitNumExpr(woditextParser::NumExprContext *ctx) = 0;

  virtual void enterUnopExpr(woditextParser::UnopExprContext *ctx) = 0;
  virtual void exitUnopExpr(woditextParser::UnopExprContext *ctx) = 0;

  virtual void enterCallExpr(woditextParser::CallExprContext *ctx) = 0;
  virtual void exitCallExpr(woditextParser::CallExprContext *ctx) = 0;

  virtual void enterParenExpr(woditextParser::ParenExprContext *ctx) = 0;
  virtual void exitParenExpr(woditextParser::ParenExprContext *ctx) = 0;

  virtual void enterBinopExpr(woditextParser::BinopExprContext *ctx) = 0;
  virtual void exitBinopExpr(woditextParser::BinopExprContext *ctx) = 0;


};

