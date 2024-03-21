
// Generated from woditext.g4 by ANTLR 4.13.0


#include "woditextVisitor.h"

#include "woditextParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct WoditextParserStaticData final {
  WoditextParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  WoditextParserStaticData(const WoditextParserStaticData&) = delete;
  WoditextParserStaticData(WoditextParserStaticData&&) = delete;
  WoditextParserStaticData& operator=(const WoditextParserStaticData&) = delete;
  WoditextParserStaticData& operator=(WoditextParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag woditextParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
WoditextParserStaticData *woditextParserStaticData = nullptr;

void woditextParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (woditextParserStaticData != nullptr) {
    return;
  }
#else
  assert(woditextParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<WoditextParserStaticData>(
    std::vector<std::string>{
      "commonlist", "common", "params", "paramlist", "param", "codeblock", 
      "ifstmt", "returntype", "vartype", "loopstmt", "stmt", "stmtcontent", 
      "comp", "call", "args", "arglist", "lhs", "dbaccess", "dbattr", "expr"
    },
    std::vector<std::string>{
      "", "'if'", "'%='", "'('", "')'", "'{'", "'}'", "'['", "']'", "'+'", 
      "'-'", "'*'", "'/'", "'%'", "'=='", "'>'", "'>='", "'<'", "'<='", 
      "'::'", "';'", "','", "'='", "'+='", "'-='", "'*='", "'/='", "", "'while'", 
      "", "'return'", "'UDB'", "'CDB'", "'SDB'"
    },
    std::vector<std::string>{
      "", "", "", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", 
      "OP_PLUS", "OP_MINUS", "OP_TIMES", "OP_DIV", "OP_MOD", "OP_EQ", "OP_GT", 
      "OP_GTE", "OP_LT", "OP_LTE", "NAMESPACE_SPECIFIER", "SEMICOLON", "COMMA", 
      "AS_EQ", "AS_PEQ", "AS_MEQ", "AS_TEQ", "AS_DEQ", "LOOP", "WHILE", 
      "BREAK", "RETURN", "UDB", "CDB", "SDB", "T_INT", "T_STR", "T_VOID", 
      "ID", "STRING", "COMMENT", "NUM", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,41,203,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,5,0,42,8,0,10,
  	0,12,0,45,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,3,2,58,8,2,
  	1,3,1,3,1,3,1,3,1,3,3,3,65,8,3,1,4,1,4,1,4,1,5,1,5,5,5,72,8,5,10,5,12,
  	5,75,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,8,1,8,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,105,8,9,1,10,
  	1,10,1,10,1,10,1,10,1,10,3,10,113,8,10,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,145,8,11,1,12,
  	1,12,1,13,1,13,1,13,1,13,1,13,1,14,1,14,3,14,156,8,14,1,15,1,15,1,15,
  	1,15,1,15,3,15,163,8,15,1,16,1,16,1,16,1,16,3,16,169,8,16,1,17,1,17,1,
  	17,1,17,1,17,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,3,19,190,8,19,1,19,1,19,1,19,1,19,1,19,1,19,5,19,198,8,19,
  	10,19,12,19,201,9,19,1,19,0,1,38,20,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,38,0,7,1,0,34,36,1,0,34,35,1,0,14,18,1,0,31,33,2,0,
  	38,38,40,40,1,0,11,13,1,0,9,10,208,0,43,1,0,0,0,2,48,1,0,0,0,4,57,1,0,
  	0,0,6,64,1,0,0,0,8,66,1,0,0,0,10,69,1,0,0,0,12,78,1,0,0,0,14,86,1,0,0,
  	0,16,88,1,0,0,0,18,104,1,0,0,0,20,112,1,0,0,0,22,144,1,0,0,0,24,146,1,
  	0,0,0,26,148,1,0,0,0,28,155,1,0,0,0,30,162,1,0,0,0,32,168,1,0,0,0,34,
  	170,1,0,0,0,36,175,1,0,0,0,38,189,1,0,0,0,40,42,3,2,1,0,41,40,1,0,0,0,
  	42,45,1,0,0,0,43,41,1,0,0,0,43,44,1,0,0,0,44,46,1,0,0,0,45,43,1,0,0,0,
  	46,47,5,0,0,1,47,1,1,0,0,0,48,49,3,14,7,0,49,50,5,37,0,0,50,51,5,3,0,
  	0,51,52,3,4,2,0,52,53,5,4,0,0,53,54,3,10,5,0,54,3,1,0,0,0,55,58,3,6,3,
  	0,56,58,1,0,0,0,57,55,1,0,0,0,57,56,1,0,0,0,58,5,1,0,0,0,59,60,3,8,4,
  	0,60,61,5,21,0,0,61,62,3,6,3,0,62,65,1,0,0,0,63,65,3,8,4,0,64,59,1,0,
  	0,0,64,63,1,0,0,0,65,7,1,0,0,0,66,67,3,16,8,0,67,68,5,37,0,0,68,9,1,0,
  	0,0,69,73,5,5,0,0,70,72,3,20,10,0,71,70,1,0,0,0,72,75,1,0,0,0,73,71,1,
  	0,0,0,73,74,1,0,0,0,74,76,1,0,0,0,75,73,1,0,0,0,76,77,5,6,0,0,77,11,1,
  	0,0,0,78,79,5,1,0,0,79,80,5,3,0,0,80,81,3,38,19,0,81,82,3,24,12,0,82,
  	83,3,38,19,0,83,84,5,4,0,0,84,85,3,10,5,0,85,13,1,0,0,0,86,87,7,0,0,0,
  	87,15,1,0,0,0,88,89,7,1,0,0,89,17,1,0,0,0,90,91,5,27,0,0,91,105,3,10,
  	5,0,92,93,5,27,0,0,93,94,5,3,0,0,94,95,3,38,19,0,95,96,5,4,0,0,96,97,
  	3,10,5,0,97,105,1,0,0,0,98,99,5,28,0,0,99,100,5,3,0,0,100,101,3,38,19,
  	0,101,102,5,4,0,0,102,103,3,10,5,0,103,105,1,0,0,0,104,90,1,0,0,0,104,
  	92,1,0,0,0,104,98,1,0,0,0,105,19,1,0,0,0,106,107,3,22,11,0,107,108,5,
  	20,0,0,108,113,1,0,0,0,109,113,3,18,9,0,110,113,3,12,6,0,111,113,3,10,
  	5,0,112,106,1,0,0,0,112,109,1,0,0,0,112,110,1,0,0,0,112,111,1,0,0,0,113,
  	21,1,0,0,0,114,115,3,16,8,0,115,116,5,37,0,0,116,145,1,0,0,0,117,118,
  	3,32,16,0,118,119,5,22,0,0,119,120,3,38,19,0,120,145,1,0,0,0,121,122,
  	3,32,16,0,122,123,5,23,0,0,123,124,3,38,19,0,124,145,1,0,0,0,125,126,
  	3,32,16,0,126,127,5,24,0,0,127,128,3,38,19,0,128,145,1,0,0,0,129,130,
  	3,32,16,0,130,131,5,25,0,0,131,132,3,38,19,0,132,145,1,0,0,0,133,134,
  	3,32,16,0,134,135,5,26,0,0,135,136,3,38,19,0,136,145,1,0,0,0,137,138,
  	3,32,16,0,138,139,5,2,0,0,139,140,3,38,19,0,140,145,1,0,0,0,141,145,5,
  	29,0,0,142,143,5,30,0,0,143,145,3,38,19,0,144,114,1,0,0,0,144,117,1,0,
  	0,0,144,121,1,0,0,0,144,125,1,0,0,0,144,129,1,0,0,0,144,133,1,0,0,0,144,
  	137,1,0,0,0,144,141,1,0,0,0,144,142,1,0,0,0,145,23,1,0,0,0,146,147,7,
  	2,0,0,147,25,1,0,0,0,148,149,5,37,0,0,149,150,5,3,0,0,150,151,3,28,14,
  	0,151,152,5,4,0,0,152,27,1,0,0,0,153,156,3,30,15,0,154,156,1,0,0,0,155,
  	153,1,0,0,0,155,154,1,0,0,0,156,29,1,0,0,0,157,158,3,38,19,0,158,159,
  	5,21,0,0,159,160,3,30,15,0,160,163,1,0,0,0,161,163,3,38,19,0,162,157,
  	1,0,0,0,162,161,1,0,0,0,163,31,1,0,0,0,164,165,3,16,8,0,165,166,5,37,
  	0,0,166,169,1,0,0,0,167,169,5,37,0,0,168,164,1,0,0,0,168,167,1,0,0,0,
  	169,33,1,0,0,0,170,171,7,3,0,0,171,172,3,36,18,0,172,173,3,36,18,0,173,
  	174,3,36,18,0,174,35,1,0,0,0,175,176,5,7,0,0,176,177,7,4,0,0,177,178,
  	5,8,0,0,178,37,1,0,0,0,179,180,6,19,-1,0,180,181,5,10,0,0,181,190,3,38,
  	19,7,182,183,5,3,0,0,183,184,3,38,19,0,184,185,5,4,0,0,185,190,1,0,0,
  	0,186,190,3,26,13,0,187,190,5,37,0,0,188,190,5,40,0,0,189,179,1,0,0,0,
  	189,182,1,0,0,0,189,186,1,0,0,0,189,187,1,0,0,0,189,188,1,0,0,0,190,199,
  	1,0,0,0,191,192,10,6,0,0,192,193,7,5,0,0,193,198,3,38,19,7,194,195,10,
  	5,0,0,195,196,7,6,0,0,196,198,3,38,19,6,197,191,1,0,0,0,197,194,1,0,0,
  	0,198,201,1,0,0,0,199,197,1,0,0,0,199,200,1,0,0,0,200,39,1,0,0,0,201,
  	199,1,0,0,0,13,43,57,64,73,104,112,144,155,162,168,189,197,199
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  woditextParserStaticData = staticData.release();
}

}

woditextParser::woditextParser(TokenStream *input) : woditextParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

woditextParser::woditextParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  woditextParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *woditextParserStaticData->atn, woditextParserStaticData->decisionToDFA, woditextParserStaticData->sharedContextCache, options);
}

woditextParser::~woditextParser() {
  delete _interpreter;
}

const atn::ATN& woditextParser::getATN() const {
  return *woditextParserStaticData->atn;
}

std::string woditextParser::getGrammarFileName() const {
  return "woditext.g4";
}

const std::vector<std::string>& woditextParser::getRuleNames() const {
  return woditextParserStaticData->ruleNames;
}

const dfa::Vocabulary& woditextParser::getVocabulary() const {
  return woditextParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView woditextParser::getSerializedATN() const {
  return woditextParserStaticData->serializedATN;
}


//----------------- CommonlistContext ------------------------------------------------------------------

woditextParser::CommonlistContext::CommonlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* woditextParser::CommonlistContext::EOF() {
  return getToken(woditextParser::EOF, 0);
}

std::vector<woditextParser::CommonContext *> woditextParser::CommonlistContext::common() {
  return getRuleContexts<woditextParser::CommonContext>();
}

woditextParser::CommonContext* woditextParser::CommonlistContext::common(size_t i) {
  return getRuleContext<woditextParser::CommonContext>(i);
}


size_t woditextParser::CommonlistContext::getRuleIndex() const {
  return woditextParser::RuleCommonlist;
}


std::any woditextParser::CommonlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitCommonlist(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::CommonlistContext* woditextParser::commonlist() {
  CommonlistContext *_localctx = _tracker.createInstance<CommonlistContext>(_ctx, getState());
  enterRule(_localctx, 0, woditextParser::RuleCommonlist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 120259084288) != 0)) {
      setState(40);
      common();
      setState(45);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(46);
    match(woditextParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommonContext ------------------------------------------------------------------

woditextParser::CommonContext::CommonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

woditextParser::ReturntypeContext* woditextParser::CommonContext::returntype() {
  return getRuleContext<woditextParser::ReturntypeContext>(0);
}

tree::TerminalNode* woditextParser::CommonContext::ID() {
  return getToken(woditextParser::ID, 0);
}

tree::TerminalNode* woditextParser::CommonContext::LPAREN() {
  return getToken(woditextParser::LPAREN, 0);
}

woditextParser::ParamsContext* woditextParser::CommonContext::params() {
  return getRuleContext<woditextParser::ParamsContext>(0);
}

tree::TerminalNode* woditextParser::CommonContext::RPAREN() {
  return getToken(woditextParser::RPAREN, 0);
}

woditextParser::CodeblockContext* woditextParser::CommonContext::codeblock() {
  return getRuleContext<woditextParser::CodeblockContext>(0);
}


size_t woditextParser::CommonContext::getRuleIndex() const {
  return woditextParser::RuleCommon;
}


std::any woditextParser::CommonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitCommon(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::CommonContext* woditextParser::common() {
  CommonContext *_localctx = _tracker.createInstance<CommonContext>(_ctx, getState());
  enterRule(_localctx, 2, woditextParser::RuleCommon);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    returntype();
    setState(49);
    match(woditextParser::ID);
    setState(50);
    match(woditextParser::LPAREN);
    setState(51);
    params();
    setState(52);
    match(woditextParser::RPAREN);
    setState(53);
    codeblock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

woditextParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

woditextParser::ParamlistContext* woditextParser::ParamsContext::paramlist() {
  return getRuleContext<woditextParser::ParamlistContext>(0);
}


size_t woditextParser::ParamsContext::getRuleIndex() const {
  return woditextParser::RuleParams;
}


std::any woditextParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::ParamsContext* woditextParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 4, woditextParser::RuleParams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(57);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case woditextParser::T_INT:
      case woditextParser::T_STR: {
        enterOuterAlt(_localctx, 1);
        setState(55);
        paramlist();
        break;
      }

      case woditextParser::RPAREN: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamlistContext ------------------------------------------------------------------

woditextParser::ParamlistContext::ParamlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

woditextParser::ParamContext* woditextParser::ParamlistContext::param() {
  return getRuleContext<woditextParser::ParamContext>(0);
}

tree::TerminalNode* woditextParser::ParamlistContext::COMMA() {
  return getToken(woditextParser::COMMA, 0);
}

woditextParser::ParamlistContext* woditextParser::ParamlistContext::paramlist() {
  return getRuleContext<woditextParser::ParamlistContext>(0);
}


size_t woditextParser::ParamlistContext::getRuleIndex() const {
  return woditextParser::RuleParamlist;
}


std::any woditextParser::ParamlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitParamlist(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::ParamlistContext* woditextParser::paramlist() {
  ParamlistContext *_localctx = _tracker.createInstance<ParamlistContext>(_ctx, getState());
  enterRule(_localctx, 6, woditextParser::RuleParamlist);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(64);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(59);
      param();
      setState(60);
      match(woditextParser::COMMA);
      setState(61);
      paramlist();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(63);
      param();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

woditextParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

woditextParser::VartypeContext* woditextParser::ParamContext::vartype() {
  return getRuleContext<woditextParser::VartypeContext>(0);
}

tree::TerminalNode* woditextParser::ParamContext::ID() {
  return getToken(woditextParser::ID, 0);
}


size_t woditextParser::ParamContext::getRuleIndex() const {
  return woditextParser::RuleParam;
}


std::any woditextParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::ParamContext* woditextParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 8, woditextParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    vartype();
    setState(67);
    match(woditextParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodeblockContext ------------------------------------------------------------------

woditextParser::CodeblockContext::CodeblockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* woditextParser::CodeblockContext::LBRACE() {
  return getToken(woditextParser::LBRACE, 0);
}

tree::TerminalNode* woditextParser::CodeblockContext::RBRACE() {
  return getToken(woditextParser::RBRACE, 0);
}

std::vector<woditextParser::StmtContext *> woditextParser::CodeblockContext::stmt() {
  return getRuleContexts<woditextParser::StmtContext>();
}

woditextParser::StmtContext* woditextParser::CodeblockContext::stmt(size_t i) {
  return getRuleContext<woditextParser::StmtContext>(i);
}


size_t woditextParser::CodeblockContext::getRuleIndex() const {
  return woditextParser::RuleCodeblock;
}


std::any woditextParser::CodeblockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitCodeblock(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::CodeblockContext* woditextParser::codeblock() {
  CodeblockContext *_localctx = _tracker.createInstance<CodeblockContext>(_ctx, getState());
  enterRule(_localctx, 10, woditextParser::RuleCodeblock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    match(woditextParser::LBRACE);
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 190991826978) != 0)) {
      setState(70);
      stmt();
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(76);
    match(woditextParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfstmtContext ------------------------------------------------------------------

woditextParser::IfstmtContext::IfstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* woditextParser::IfstmtContext::LPAREN() {
  return getToken(woditextParser::LPAREN, 0);
}

std::vector<woditextParser::ExprContext *> woditextParser::IfstmtContext::expr() {
  return getRuleContexts<woditextParser::ExprContext>();
}

woditextParser::ExprContext* woditextParser::IfstmtContext::expr(size_t i) {
  return getRuleContext<woditextParser::ExprContext>(i);
}

woditextParser::CompContext* woditextParser::IfstmtContext::comp() {
  return getRuleContext<woditextParser::CompContext>(0);
}

tree::TerminalNode* woditextParser::IfstmtContext::RPAREN() {
  return getToken(woditextParser::RPAREN, 0);
}

woditextParser::CodeblockContext* woditextParser::IfstmtContext::codeblock() {
  return getRuleContext<woditextParser::CodeblockContext>(0);
}


size_t woditextParser::IfstmtContext::getRuleIndex() const {
  return woditextParser::RuleIfstmt;
}


std::any woditextParser::IfstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitIfstmt(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::IfstmtContext* woditextParser::ifstmt() {
  IfstmtContext *_localctx = _tracker.createInstance<IfstmtContext>(_ctx, getState());
  enterRule(_localctx, 12, woditextParser::RuleIfstmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    match(woditextParser::T__0);
    setState(79);
    match(woditextParser::LPAREN);
    setState(80);
    expr(0);
    setState(81);
    comp();
    setState(82);
    expr(0);
    setState(83);
    match(woditextParser::RPAREN);
    setState(84);
    codeblock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturntypeContext ------------------------------------------------------------------

woditextParser::ReturntypeContext::ReturntypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* woditextParser::ReturntypeContext::T_VOID() {
  return getToken(woditextParser::T_VOID, 0);
}

tree::TerminalNode* woditextParser::ReturntypeContext::T_INT() {
  return getToken(woditextParser::T_INT, 0);
}

tree::TerminalNode* woditextParser::ReturntypeContext::T_STR() {
  return getToken(woditextParser::T_STR, 0);
}


size_t woditextParser::ReturntypeContext::getRuleIndex() const {
  return woditextParser::RuleReturntype;
}


std::any woditextParser::ReturntypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitReturntype(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::ReturntypeContext* woditextParser::returntype() {
  ReturntypeContext *_localctx = _tracker.createInstance<ReturntypeContext>(_ctx, getState());
  enterRule(_localctx, 14, woditextParser::RuleReturntype);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 120259084288) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VartypeContext ------------------------------------------------------------------

woditextParser::VartypeContext::VartypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* woditextParser::VartypeContext::T_INT() {
  return getToken(woditextParser::T_INT, 0);
}

tree::TerminalNode* woditextParser::VartypeContext::T_STR() {
  return getToken(woditextParser::T_STR, 0);
}


size_t woditextParser::VartypeContext::getRuleIndex() const {
  return woditextParser::RuleVartype;
}


std::any woditextParser::VartypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitVartype(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::VartypeContext* woditextParser::vartype() {
  VartypeContext *_localctx = _tracker.createInstance<VartypeContext>(_ctx, getState());
  enterRule(_localctx, 16, woditextParser::RuleVartype);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    _la = _input->LA(1);
    if (!(_la == woditextParser::T_INT

    || _la == woditextParser::T_STR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopstmtContext ------------------------------------------------------------------

woditextParser::LoopstmtContext::LoopstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* woditextParser::LoopstmtContext::LOOP() {
  return getToken(woditextParser::LOOP, 0);
}

woditextParser::CodeblockContext* woditextParser::LoopstmtContext::codeblock() {
  return getRuleContext<woditextParser::CodeblockContext>(0);
}

tree::TerminalNode* woditextParser::LoopstmtContext::LPAREN() {
  return getToken(woditextParser::LPAREN, 0);
}

woditextParser::ExprContext* woditextParser::LoopstmtContext::expr() {
  return getRuleContext<woditextParser::ExprContext>(0);
}

tree::TerminalNode* woditextParser::LoopstmtContext::RPAREN() {
  return getToken(woditextParser::RPAREN, 0);
}

tree::TerminalNode* woditextParser::LoopstmtContext::WHILE() {
  return getToken(woditextParser::WHILE, 0);
}


size_t woditextParser::LoopstmtContext::getRuleIndex() const {
  return woditextParser::RuleLoopstmt;
}


std::any woditextParser::LoopstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitLoopstmt(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::LoopstmtContext* woditextParser::loopstmt() {
  LoopstmtContext *_localctx = _tracker.createInstance<LoopstmtContext>(_ctx, getState());
  enterRule(_localctx, 18, woditextParser::RuleLoopstmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(104);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(90);
      match(woditextParser::LOOP);
      setState(91);
      codeblock();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(92);
      match(woditextParser::LOOP);
      setState(93);
      match(woditextParser::LPAREN);
      setState(94);
      expr(0);
      setState(95);
      match(woditextParser::RPAREN);
      setState(96);
      codeblock();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(98);
      match(woditextParser::WHILE);
      setState(99);
      match(woditextParser::LPAREN);
      setState(100);
      expr(0);
      setState(101);
      match(woditextParser::RPAREN);
      setState(102);
      codeblock();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

woditextParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

woditextParser::StmtcontentContext* woditextParser::StmtContext::stmtcontent() {
  return getRuleContext<woditextParser::StmtcontentContext>(0);
}

tree::TerminalNode* woditextParser::StmtContext::SEMICOLON() {
  return getToken(woditextParser::SEMICOLON, 0);
}

woditextParser::LoopstmtContext* woditextParser::StmtContext::loopstmt() {
  return getRuleContext<woditextParser::LoopstmtContext>(0);
}

woditextParser::IfstmtContext* woditextParser::StmtContext::ifstmt() {
  return getRuleContext<woditextParser::IfstmtContext>(0);
}

woditextParser::CodeblockContext* woditextParser::StmtContext::codeblock() {
  return getRuleContext<woditextParser::CodeblockContext>(0);
}


size_t woditextParser::StmtContext::getRuleIndex() const {
  return woditextParser::RuleStmt;
}


std::any woditextParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::StmtContext* woditextParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 20, woditextParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(112);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case woditextParser::BREAK:
      case woditextParser::RETURN:
      case woditextParser::T_INT:
      case woditextParser::T_STR:
      case woditextParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(106);
        stmtcontent();
        setState(107);
        match(woditextParser::SEMICOLON);
        break;
      }

      case woditextParser::LOOP:
      case woditextParser::WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(109);
        loopstmt();
        break;
      }

      case woditextParser::T__0: {
        enterOuterAlt(_localctx, 3);
        setState(110);
        ifstmt();
        break;
      }

      case woditextParser::LBRACE: {
        enterOuterAlt(_localctx, 4);
        setState(111);
        codeblock();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtcontentContext ------------------------------------------------------------------

woditextParser::StmtcontentContext::StmtcontentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t woditextParser::StmtcontentContext::getRuleIndex() const {
  return woditextParser::RuleStmtcontent;
}

void woditextParser::StmtcontentContext::copyFrom(StmtcontentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ReturnContext ------------------------------------------------------------------

tree::TerminalNode* woditextParser::ReturnContext::RETURN() {
  return getToken(woditextParser::RETURN, 0);
}

woditextParser::ExprContext* woditextParser::ReturnContext::expr() {
  return getRuleContext<woditextParser::ExprContext>(0);
}

woditextParser::ReturnContext::ReturnContext(StmtcontentContext *ctx) { copyFrom(ctx); }


std::any woditextParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakContext ------------------------------------------------------------------

tree::TerminalNode* woditextParser::BreakContext::BREAK() {
  return getToken(woditextParser::BREAK, 0);
}

woditextParser::BreakContext::BreakContext(StmtcontentContext *ctx) { copyFrom(ctx); }


std::any woditextParser::BreakContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitBreak(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclContext ------------------------------------------------------------------

woditextParser::VartypeContext* woditextParser::DeclContext::vartype() {
  return getRuleContext<woditextParser::VartypeContext>(0);
}

tree::TerminalNode* woditextParser::DeclContext::ID() {
  return getToken(woditextParser::ID, 0);
}

woditextParser::DeclContext::DeclContext(StmtcontentContext *ctx) { copyFrom(ctx); }


std::any woditextParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

woditextParser::LhsContext* woditextParser::AssignContext::lhs() {
  return getRuleContext<woditextParser::LhsContext>(0);
}

tree::TerminalNode* woditextParser::AssignContext::AS_EQ() {
  return getToken(woditextParser::AS_EQ, 0);
}

woditextParser::ExprContext* woditextParser::AssignContext::expr() {
  return getRuleContext<woditextParser::ExprContext>(0);
}

tree::TerminalNode* woditextParser::AssignContext::AS_PEQ() {
  return getToken(woditextParser::AS_PEQ, 0);
}

tree::TerminalNode* woditextParser::AssignContext::AS_MEQ() {
  return getToken(woditextParser::AS_MEQ, 0);
}

tree::TerminalNode* woditextParser::AssignContext::AS_TEQ() {
  return getToken(woditextParser::AS_TEQ, 0);
}

tree::TerminalNode* woditextParser::AssignContext::AS_DEQ() {
  return getToken(woditextParser::AS_DEQ, 0);
}

woditextParser::AssignContext::AssignContext(StmtcontentContext *ctx) { copyFrom(ctx); }


std::any woditextParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
woditextParser::StmtcontentContext* woditextParser::stmtcontent() {
  StmtcontentContext *_localctx = _tracker.createInstance<StmtcontentContext>(_ctx, getState());
  enterRule(_localctx, 22, woditextParser::RuleStmtcontent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<woditextParser::DeclContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(114);
      vartype();
      setState(115);
      match(woditextParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<woditextParser::AssignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(117);
      lhs();
      setState(118);
      match(woditextParser::AS_EQ);
      setState(119);
      expr(0);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<woditextParser::AssignContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(121);
      lhs();
      setState(122);
      match(woditextParser::AS_PEQ);
      setState(123);
      expr(0);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<woditextParser::AssignContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(125);
      lhs();
      setState(126);
      match(woditextParser::AS_MEQ);
      setState(127);
      expr(0);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<woditextParser::AssignContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(129);
      lhs();
      setState(130);
      match(woditextParser::AS_TEQ);
      setState(131);
      expr(0);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<woditextParser::AssignContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(133);
      lhs();
      setState(134);
      match(woditextParser::AS_DEQ);
      setState(135);
      expr(0);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<woditextParser::AssignContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(137);
      lhs();
      setState(138);
      match(woditextParser::T__1);
      setState(139);
      expr(0);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<woditextParser::BreakContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(141);
      match(woditextParser::BREAK);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<woditextParser::ReturnContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(142);
      match(woditextParser::RETURN);
      setState(143);
      expr(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompContext ------------------------------------------------------------------

woditextParser::CompContext::CompContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* woditextParser::CompContext::OP_EQ() {
  return getToken(woditextParser::OP_EQ, 0);
}

tree::TerminalNode* woditextParser::CompContext::OP_GT() {
  return getToken(woditextParser::OP_GT, 0);
}

tree::TerminalNode* woditextParser::CompContext::OP_GTE() {
  return getToken(woditextParser::OP_GTE, 0);
}

tree::TerminalNode* woditextParser::CompContext::OP_LT() {
  return getToken(woditextParser::OP_LT, 0);
}

tree::TerminalNode* woditextParser::CompContext::OP_LTE() {
  return getToken(woditextParser::OP_LTE, 0);
}


size_t woditextParser::CompContext::getRuleIndex() const {
  return woditextParser::RuleComp;
}


std::any woditextParser::CompContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitComp(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::CompContext* woditextParser::comp() {
  CompContext *_localctx = _tracker.createInstance<CompContext>(_ctx, getState());
  enterRule(_localctx, 24, woditextParser::RuleComp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 507904) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallContext ------------------------------------------------------------------

woditextParser::CallContext::CallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* woditextParser::CallContext::ID() {
  return getToken(woditextParser::ID, 0);
}

tree::TerminalNode* woditextParser::CallContext::LPAREN() {
  return getToken(woditextParser::LPAREN, 0);
}

woditextParser::ArgsContext* woditextParser::CallContext::args() {
  return getRuleContext<woditextParser::ArgsContext>(0);
}

tree::TerminalNode* woditextParser::CallContext::RPAREN() {
  return getToken(woditextParser::RPAREN, 0);
}


size_t woditextParser::CallContext::getRuleIndex() const {
  return woditextParser::RuleCall;
}


std::any woditextParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::CallContext* woditextParser::call() {
  CallContext *_localctx = _tracker.createInstance<CallContext>(_ctx, getState());
  enterRule(_localctx, 26, woditextParser::RuleCall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    match(woditextParser::ID);
    setState(149);
    match(woditextParser::LPAREN);
    setState(150);
    args();
    setState(151);
    match(woditextParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsContext ------------------------------------------------------------------

woditextParser::ArgsContext::ArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

woditextParser::ArglistContext* woditextParser::ArgsContext::arglist() {
  return getRuleContext<woditextParser::ArglistContext>(0);
}


size_t woditextParser::ArgsContext::getRuleIndex() const {
  return woditextParser::RuleArgs;
}


std::any woditextParser::ArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitArgs(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::ArgsContext* woditextParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 28, woditextParser::RuleArgs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(155);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case woditextParser::LPAREN:
      case woditextParser::OP_MINUS:
      case woditextParser::ID:
      case woditextParser::NUM: {
        enterOuterAlt(_localctx, 1);
        setState(153);
        arglist();
        break;
      }

      case woditextParser::RPAREN: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArglistContext ------------------------------------------------------------------

woditextParser::ArglistContext::ArglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

woditextParser::ExprContext* woditextParser::ArglistContext::expr() {
  return getRuleContext<woditextParser::ExprContext>(0);
}

tree::TerminalNode* woditextParser::ArglistContext::COMMA() {
  return getToken(woditextParser::COMMA, 0);
}

woditextParser::ArglistContext* woditextParser::ArglistContext::arglist() {
  return getRuleContext<woditextParser::ArglistContext>(0);
}


size_t woditextParser::ArglistContext::getRuleIndex() const {
  return woditextParser::RuleArglist;
}


std::any woditextParser::ArglistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitArglist(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::ArglistContext* woditextParser::arglist() {
  ArglistContext *_localctx = _tracker.createInstance<ArglistContext>(_ctx, getState());
  enterRule(_localctx, 30, woditextParser::RuleArglist);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(157);
      expr(0);
      setState(158);
      match(woditextParser::COMMA);
      setState(159);
      arglist();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(161);
      expr(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LhsContext ------------------------------------------------------------------

woditextParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

woditextParser::VartypeContext* woditextParser::LhsContext::vartype() {
  return getRuleContext<woditextParser::VartypeContext>(0);
}

tree::TerminalNode* woditextParser::LhsContext::ID() {
  return getToken(woditextParser::ID, 0);
}


size_t woditextParser::LhsContext::getRuleIndex() const {
  return woditextParser::RuleLhs;
}


std::any woditextParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::LhsContext* woditextParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 32, woditextParser::RuleLhs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(168);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case woditextParser::T_INT:
      case woditextParser::T_STR: {
        enterOuterAlt(_localctx, 1);
        setState(164);
        vartype();
        setState(165);
        match(woditextParser::ID);
        break;
      }

      case woditextParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(167);
        match(woditextParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DbaccessContext ------------------------------------------------------------------

woditextParser::DbaccessContext::DbaccessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<woditextParser::DbattrContext *> woditextParser::DbaccessContext::dbattr() {
  return getRuleContexts<woditextParser::DbattrContext>();
}

woditextParser::DbattrContext* woditextParser::DbaccessContext::dbattr(size_t i) {
  return getRuleContext<woditextParser::DbattrContext>(i);
}

tree::TerminalNode* woditextParser::DbaccessContext::UDB() {
  return getToken(woditextParser::UDB, 0);
}

tree::TerminalNode* woditextParser::DbaccessContext::CDB() {
  return getToken(woditextParser::CDB, 0);
}

tree::TerminalNode* woditextParser::DbaccessContext::SDB() {
  return getToken(woditextParser::SDB, 0);
}


size_t woditextParser::DbaccessContext::getRuleIndex() const {
  return woditextParser::RuleDbaccess;
}


std::any woditextParser::DbaccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitDbaccess(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::DbaccessContext* woditextParser::dbaccess() {
  DbaccessContext *_localctx = _tracker.createInstance<DbaccessContext>(_ctx, getState());
  enterRule(_localctx, 34, woditextParser::RuleDbaccess);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 15032385536) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(171);
    dbattr();
    setState(172);
    dbattr();
    setState(173);
    dbattr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DbattrContext ------------------------------------------------------------------

woditextParser::DbattrContext::DbattrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* woditextParser::DbattrContext::LBRACK() {
  return getToken(woditextParser::LBRACK, 0);
}

tree::TerminalNode* woditextParser::DbattrContext::RBRACK() {
  return getToken(woditextParser::RBRACK, 0);
}

tree::TerminalNode* woditextParser::DbattrContext::NUM() {
  return getToken(woditextParser::NUM, 0);
}

tree::TerminalNode* woditextParser::DbattrContext::STRING() {
  return getToken(woditextParser::STRING, 0);
}


size_t woditextParser::DbattrContext::getRuleIndex() const {
  return woditextParser::RuleDbattr;
}


std::any woditextParser::DbattrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitDbattr(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::DbattrContext* woditextParser::dbattr() {
  DbattrContext *_localctx = _tracker.createInstance<DbattrContext>(_ctx, getState());
  enterRule(_localctx, 36, woditextParser::RuleDbattr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(woditextParser::LBRACK);
    setState(176);
    _la = _input->LA(1);
    if (!(_la == woditextParser::STRING

    || _la == woditextParser::NUM)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(177);
    match(woditextParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

woditextParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t woditextParser::ExprContext::getRuleIndex() const {
  return woditextParser::RuleExpr;
}

void woditextParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IdExprContext ------------------------------------------------------------------

tree::TerminalNode* woditextParser::IdExprContext::ID() {
  return getToken(woditextParser::ID, 0);
}

woditextParser::IdExprContext::IdExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any woditextParser::IdExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitIdExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumExprContext ------------------------------------------------------------------

tree::TerminalNode* woditextParser::NumExprContext::NUM() {
  return getToken(woditextParser::NUM, 0);
}

woditextParser::NumExprContext::NumExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any woditextParser::NumExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitNumExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnopExprContext ------------------------------------------------------------------

tree::TerminalNode* woditextParser::UnopExprContext::OP_MINUS() {
  return getToken(woditextParser::OP_MINUS, 0);
}

woditextParser::ExprContext* woditextParser::UnopExprContext::expr() {
  return getRuleContext<woditextParser::ExprContext>(0);
}

woditextParser::UnopExprContext::UnopExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any woditextParser::UnopExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitUnopExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallExprContext ------------------------------------------------------------------

woditextParser::CallContext* woditextParser::CallExprContext::call() {
  return getRuleContext<woditextParser::CallContext>(0);
}

woditextParser::CallExprContext::CallExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any woditextParser::CallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

tree::TerminalNode* woditextParser::ParenExprContext::LPAREN() {
  return getToken(woditextParser::LPAREN, 0);
}

woditextParser::ExprContext* woditextParser::ParenExprContext::expr() {
  return getRuleContext<woditextParser::ExprContext>(0);
}

tree::TerminalNode* woditextParser::ParenExprContext::RPAREN() {
  return getToken(woditextParser::RPAREN, 0);
}

woditextParser::ParenExprContext::ParenExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any woditextParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinopExprContext ------------------------------------------------------------------

std::vector<woditextParser::ExprContext *> woditextParser::BinopExprContext::expr() {
  return getRuleContexts<woditextParser::ExprContext>();
}

woditextParser::ExprContext* woditextParser::BinopExprContext::expr(size_t i) {
  return getRuleContext<woditextParser::ExprContext>(i);
}

tree::TerminalNode* woditextParser::BinopExprContext::OP_TIMES() {
  return getToken(woditextParser::OP_TIMES, 0);
}

tree::TerminalNode* woditextParser::BinopExprContext::OP_DIV() {
  return getToken(woditextParser::OP_DIV, 0);
}

tree::TerminalNode* woditextParser::BinopExprContext::OP_MOD() {
  return getToken(woditextParser::OP_MOD, 0);
}

tree::TerminalNode* woditextParser::BinopExprContext::OP_PLUS() {
  return getToken(woditextParser::OP_PLUS, 0);
}

tree::TerminalNode* woditextParser::BinopExprContext::OP_MINUS() {
  return getToken(woditextParser::OP_MINUS, 0);
}

woditextParser::BinopExprContext::BinopExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any woditextParser::BinopExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<woditextVisitor*>(visitor))
    return parserVisitor->visitBinopExpr(this);
  else
    return visitor->visitChildren(this);
}

woditextParser::ExprContext* woditextParser::expr() {
   return expr(0);
}

woditextParser::ExprContext* woditextParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  woditextParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  woditextParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, woditextParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UnopExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(180);
      match(woditextParser::OP_MINUS);
      setState(181);
      expr(7);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(182);
      match(woditextParser::LPAREN);
      setState(183);
      expr(0);
      setState(184);
      match(woditextParser::RPAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(186);
      call();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<IdExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(187);
      match(woditextParser::ID);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NumExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(188);
      match(woditextParser::NUM);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(199);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(197);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinopExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(191);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(192);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 14336) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(193);
          expr(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinopExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(194);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(195);
          _la = _input->LA(1);
          if (!(_la == woditextParser::OP_PLUS

          || _la == woditextParser::OP_MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(196);
          expr(6);
          break;
        }

        default:
          break;
        } 
      }
      setState(201);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool woditextParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 19: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool woditextParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

void woditextParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  woditextParserInitialize();
#else
  ::antlr4::internal::call_once(woditextParserOnceFlag, woditextParserInitialize);
#endif
}
