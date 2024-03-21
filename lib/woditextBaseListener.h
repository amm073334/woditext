
// Generated from woditext.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "woditextListener.h"


/**
 * This class provides an empty implementation of woditextListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  woditextBaseListener : public woditextListener {
public:

  virtual void enterCommonlist(woditextParser::CommonlistContext * /*ctx*/) override { }
  virtual void exitCommonlist(woditextParser::CommonlistContext * /*ctx*/) override { }

  virtual void enterCommon(woditextParser::CommonContext * /*ctx*/) override { }
  virtual void exitCommon(woditextParser::CommonContext * /*ctx*/) override { }

  virtual void enterParams(woditextParser::ParamsContext * /*ctx*/) override { }
  virtual void exitParams(woditextParser::ParamsContext * /*ctx*/) override { }

  virtual void enterParamlist(woditextParser::ParamlistContext * /*ctx*/) override { }
  virtual void exitParamlist(woditextParser::ParamlistContext * /*ctx*/) override { }

  virtual void enterParam(woditextParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(woditextParser::ParamContext * /*ctx*/) override { }

  virtual void enterCodeblock(woditextParser::CodeblockContext * /*ctx*/) override { }
  virtual void exitCodeblock(woditextParser::CodeblockContext * /*ctx*/) override { }

  virtual void enterIfstmt(woditextParser::IfstmtContext * /*ctx*/) override { }
  virtual void exitIfstmt(woditextParser::IfstmtContext * /*ctx*/) override { }

  virtual void enterReturntype(woditextParser::ReturntypeContext * /*ctx*/) override { }
  virtual void exitReturntype(woditextParser::ReturntypeContext * /*ctx*/) override { }

  virtual void enterVartype(woditextParser::VartypeContext * /*ctx*/) override { }
  virtual void exitVartype(woditextParser::VartypeContext * /*ctx*/) override { }

  virtual void enterLoopstmt(woditextParser::LoopstmtContext * /*ctx*/) override { }
  virtual void exitLoopstmt(woditextParser::LoopstmtContext * /*ctx*/) override { }

  virtual void enterStmt(woditextParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(woditextParser::StmtContext * /*ctx*/) override { }

  virtual void enterDecl(woditextParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(woditextParser::DeclContext * /*ctx*/) override { }

  virtual void enterAssign(woditextParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(woditextParser::AssignContext * /*ctx*/) override { }

  virtual void enterBreak(woditextParser::BreakContext * /*ctx*/) override { }
  virtual void exitBreak(woditextParser::BreakContext * /*ctx*/) override { }

  virtual void enterReturn(woditextParser::ReturnContext * /*ctx*/) override { }
  virtual void exitReturn(woditextParser::ReturnContext * /*ctx*/) override { }

  virtual void enterComp(woditextParser::CompContext * /*ctx*/) override { }
  virtual void exitComp(woditextParser::CompContext * /*ctx*/) override { }

  virtual void enterUnop(woditextParser::UnopContext * /*ctx*/) override { }
  virtual void exitUnop(woditextParser::UnopContext * /*ctx*/) override { }

  virtual void enterCall(woditextParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(woditextParser::CallContext * /*ctx*/) override { }

  virtual void enterArgs(woditextParser::ArgsContext * /*ctx*/) override { }
  virtual void exitArgs(woditextParser::ArgsContext * /*ctx*/) override { }

  virtual void enterArglist(woditextParser::ArglistContext * /*ctx*/) override { }
  virtual void exitArglist(woditextParser::ArglistContext * /*ctx*/) override { }

  virtual void enterLhs(woditextParser::LhsContext * /*ctx*/) override { }
  virtual void exitLhs(woditextParser::LhsContext * /*ctx*/) override { }

  virtual void enterDbaccess(woditextParser::DbaccessContext * /*ctx*/) override { }
  virtual void exitDbaccess(woditextParser::DbaccessContext * /*ctx*/) override { }

  virtual void enterDbattr(woditextParser::DbattrContext * /*ctx*/) override { }
  virtual void exitDbattr(woditextParser::DbattrContext * /*ctx*/) override { }

  virtual void enterIdExpr(woditextParser::IdExprContext * /*ctx*/) override { }
  virtual void exitIdExpr(woditextParser::IdExprContext * /*ctx*/) override { }

  virtual void enterNumExpr(woditextParser::NumExprContext * /*ctx*/) override { }
  virtual void exitNumExpr(woditextParser::NumExprContext * /*ctx*/) override { }

  virtual void enterUnopExpr(woditextParser::UnopExprContext * /*ctx*/) override { }
  virtual void exitUnopExpr(woditextParser::UnopExprContext * /*ctx*/) override { }

  virtual void enterCallExpr(woditextParser::CallExprContext * /*ctx*/) override { }
  virtual void exitCallExpr(woditextParser::CallExprContext * /*ctx*/) override { }

  virtual void enterParenExpr(woditextParser::ParenExprContext * /*ctx*/) override { }
  virtual void exitParenExpr(woditextParser::ParenExprContext * /*ctx*/) override { }

  virtual void enterBinopExpr(woditextParser::BinopExprContext * /*ctx*/) override { }
  virtual void exitBinopExpr(woditextParser::BinopExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

