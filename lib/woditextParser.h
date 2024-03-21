
// Generated from woditext.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  woditextParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, LPAREN = 3, RPAREN = 4, LBRACE = 5, RBRACE = 6, 
    LBRACK = 7, RBRACK = 8, OP_PLUS = 9, OP_MINUS = 10, OP_TIMES = 11, OP_DIV = 12, 
    OP_MOD = 13, OP_EQ = 14, OP_GT = 15, OP_GTE = 16, OP_LT = 17, OP_LTE = 18, 
    NAMESPACE_SPECIFIER = 19, SEMICOLON = 20, COMMA = 21, AS_EQ = 22, AS_PEQ = 23, 
    AS_MEQ = 24, AS_TEQ = 25, AS_DEQ = 26, LOOP = 27, WHILE = 28, BREAK = 29, 
    RETURN = 30, UDB = 31, CDB = 32, SDB = 33, T_INT = 34, T_STR = 35, T_VOID = 36, 
    ID = 37, STRING = 38, COMMENT = 39, NUM = 40, WS = 41
  };

  enum {
    RuleCommonlist = 0, RuleCommon = 1, RuleParams = 2, RuleParamlist = 3, 
    RuleParam = 4, RuleCodeblock = 5, RuleIfstmt = 6, RuleReturntype = 7, 
    RuleVartype = 8, RuleLoopstmt = 9, RuleStmt = 10, RuleStmtcontent = 11, 
    RuleComp = 12, RuleCall = 13, RuleArgs = 14, RuleArglist = 15, RuleLhs = 16, 
    RuleDbaccess = 17, RuleDbattr = 18, RuleExpr = 19
  };

  explicit woditextParser(antlr4::TokenStream *input);

  woditextParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~woditextParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class CommonlistContext;
  class CommonContext;
  class ParamsContext;
  class ParamlistContext;
  class ParamContext;
  class CodeblockContext;
  class IfstmtContext;
  class ReturntypeContext;
  class VartypeContext;
  class LoopstmtContext;
  class StmtContext;
  class StmtcontentContext;
  class CompContext;
  class CallContext;
  class ArgsContext;
  class ArglistContext;
  class LhsContext;
  class DbaccessContext;
  class DbattrContext;
  class ExprContext; 

  class  CommonlistContext : public antlr4::ParserRuleContext {
  public:
    CommonlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<CommonContext *> common();
    CommonContext* common(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommonlistContext* commonlist();

  class  CommonContext : public antlr4::ParserRuleContext {
  public:
    CommonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ReturntypeContext *returntype();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    ParamsContext *params();
    antlr4::tree::TerminalNode *RPAREN();
    CodeblockContext *codeblock();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommonContext* common();

  class  ParamsContext : public antlr4::ParserRuleContext {
  public:
    ParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamlistContext *paramlist();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamsContext* params();

  class  ParamlistContext : public antlr4::ParserRuleContext {
  public:
    ParamlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamContext *param();
    antlr4::tree::TerminalNode *COMMA();
    ParamlistContext *paramlist();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamlistContext* paramlist();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VartypeContext *vartype();
    antlr4::tree::TerminalNode *ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamContext* param();

  class  CodeblockContext : public antlr4::ParserRuleContext {
  public:
    CodeblockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodeblockContext* codeblock();

  class  IfstmtContext : public antlr4::ParserRuleContext {
  public:
    IfstmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    CompContext *comp();
    antlr4::tree::TerminalNode *RPAREN();
    CodeblockContext *codeblock();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfstmtContext* ifstmt();

  class  ReturntypeContext : public antlr4::ParserRuleContext {
  public:
    ReturntypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *T_VOID();
    antlr4::tree::TerminalNode *T_INT();
    antlr4::tree::TerminalNode *T_STR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturntypeContext* returntype();

  class  VartypeContext : public antlr4::ParserRuleContext {
  public:
    VartypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *T_INT();
    antlr4::tree::TerminalNode *T_STR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VartypeContext* vartype();

  class  LoopstmtContext : public antlr4::ParserRuleContext {
  public:
    LoopstmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOOP();
    CodeblockContext *codeblock();
    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *WHILE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopstmtContext* loopstmt();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StmtcontentContext *stmtcontent();
    antlr4::tree::TerminalNode *SEMICOLON();
    LoopstmtContext *loopstmt();
    IfstmtContext *ifstmt();
    CodeblockContext *codeblock();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  StmtcontentContext : public antlr4::ParserRuleContext {
  public:
    StmtcontentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtcontentContext() = default;
    void copyFrom(StmtcontentContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ReturnContext : public StmtcontentContext {
  public:
    ReturnContext(StmtcontentContext *ctx);

    antlr4::tree::TerminalNode *RETURN();
    ExprContext *expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BreakContext : public StmtcontentContext {
  public:
    BreakContext(StmtcontentContext *ctx);

    antlr4::tree::TerminalNode *BREAK();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeclContext : public StmtcontentContext {
  public:
    DeclContext(StmtcontentContext *ctx);

    VartypeContext *vartype();
    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignContext : public StmtcontentContext {
  public:
    AssignContext(StmtcontentContext *ctx);

    LhsContext *lhs();
    antlr4::tree::TerminalNode *AS_EQ();
    ExprContext *expr();
    antlr4::tree::TerminalNode *AS_PEQ();
    antlr4::tree::TerminalNode *AS_MEQ();
    antlr4::tree::TerminalNode *AS_TEQ();
    antlr4::tree::TerminalNode *AS_DEQ();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StmtcontentContext* stmtcontent();

  class  CompContext : public antlr4::ParserRuleContext {
  public:
    CompContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_EQ();
    antlr4::tree::TerminalNode *OP_GT();
    antlr4::tree::TerminalNode *OP_GTE();
    antlr4::tree::TerminalNode *OP_LT();
    antlr4::tree::TerminalNode *OP_LTE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompContext* comp();

  class  CallContext : public antlr4::ParserRuleContext {
  public:
    CallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    ArgsContext *args();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallContext* call();

  class  ArgsContext : public antlr4::ParserRuleContext {
  public:
    ArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArglistContext *arglist();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgsContext* args();

  class  ArglistContext : public antlr4::ParserRuleContext {
  public:
    ArglistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *COMMA();
    ArglistContext *arglist();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArglistContext* arglist();

  class  LhsContext : public antlr4::ParserRuleContext {
  public:
    LhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VartypeContext *vartype();
    antlr4::tree::TerminalNode *ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LhsContext* lhs();

  class  DbaccessContext : public antlr4::ParserRuleContext {
  public:
    DbaccessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DbattrContext *> dbattr();
    DbattrContext* dbattr(size_t i);
    antlr4::tree::TerminalNode *UDB();
    antlr4::tree::TerminalNode *CDB();
    antlr4::tree::TerminalNode *SDB();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DbaccessContext* dbaccess();

  class  DbattrContext : public antlr4::ParserRuleContext {
  public:
    DbattrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();
    antlr4::tree::TerminalNode *NUM();
    antlr4::tree::TerminalNode *STRING();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DbattrContext* dbattr();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IdExprContext : public ExprContext {
  public:
    IdExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumExprContext : public ExprContext {
  public:
    NumExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *NUM();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnopExprContext : public ExprContext {
  public:
    UnopExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *OP_MINUS();
    ExprContext *expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CallExprContext : public ExprContext {
  public:
    CallExprContext(ExprContext *ctx);

    CallContext *call();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenExprContext : public ExprContext {
  public:
    ParenExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinopExprContext : public ExprContext {
  public:
    BinopExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *OP_TIMES();
    antlr4::tree::TerminalNode *OP_DIV();
    antlr4::tree::TerminalNode *OP_MOD();
    antlr4::tree::TerminalNode *OP_PLUS();
    antlr4::tree::TerminalNode *OP_MINUS();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

