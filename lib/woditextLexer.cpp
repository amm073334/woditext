
// Generated from woditext.g4 by ANTLR 4.13.0


#include "woditextLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct WoditextLexerStaticData final {
  WoditextLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  WoditextLexerStaticData(const WoditextLexerStaticData&) = delete;
  WoditextLexerStaticData(WoditextLexerStaticData&&) = delete;
  WoditextLexerStaticData& operator=(const WoditextLexerStaticData&) = delete;
  WoditextLexerStaticData& operator=(WoditextLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag woditextlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
WoditextLexerStaticData *woditextlexerLexerStaticData = nullptr;

void woditextlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (woditextlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(woditextlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<WoditextLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", 
      "RBRACK", "OP_PLUS", "OP_MINUS", "OP_TIMES", "OP_DIV", "OP_MOD", "OP_EQ", 
      "OP_GT", "OP_GTE", "OP_LT", "OP_LTE", "NAMESPACE_SPECIFIER", "SEMICOLON", 
      "COMMA", "AS_EQ", "AS_PEQ", "AS_MEQ", "AS_TEQ", "AS_DEQ", "LOOP", 
      "WHILE", "BREAK", "RETURN", "UDB", "CDB", "SDB", "T_INT", "T_STR", 
      "T_VOID", "ID", "STRING", "COMMENT", "NUM", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,41,257,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,1,0,1,0,1,0,1,
  	1,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,
  	1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,15,1,15,
  	1,15,1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,18,1,19,1,19,1,20,1,20,1,21,
  	1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,3,26,153,8,26,1,27,1,27,1,27,1,27,1,27,
  	1,27,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,3,28,171,8,28,
  	1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,31,1,31,1,31,
  	1,31,1,32,1,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,3,33,197,8,33,1,34,
  	1,34,1,34,1,34,1,34,1,34,3,34,205,8,34,1,35,1,35,1,35,1,35,1,35,1,35,
  	1,35,3,35,214,8,35,1,36,1,36,5,36,218,8,36,10,36,12,36,221,9,36,1,37,
  	1,37,5,37,225,8,37,10,37,12,37,228,9,37,1,37,1,37,1,38,1,38,1,38,1,38,
  	5,38,236,8,38,10,38,12,38,239,9,38,1,38,1,38,1,39,3,39,244,8,39,1,39,
  	4,39,247,8,39,11,39,12,39,248,1,40,4,40,252,8,40,11,40,12,40,253,1,40,
  	1,40,0,0,41,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,
  	25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,
  	24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,
  	71,36,73,37,75,38,77,39,79,40,81,41,1,0,6,3,0,65,90,95,95,97,122,4,0,
  	48,57,65,90,95,95,97,122,2,0,34,34,94,94,2,0,10,10,13,13,1,0,48,57,3,
  	0,9,10,13,13,32,32,267,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,
  	0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,
  	1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,
  	0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,
  	0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,
  	1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,
  	0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,
  	0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,1,83,
  	1,0,0,0,3,86,1,0,0,0,5,89,1,0,0,0,7,91,1,0,0,0,9,93,1,0,0,0,11,95,1,0,
  	0,0,13,97,1,0,0,0,15,99,1,0,0,0,17,101,1,0,0,0,19,103,1,0,0,0,21,105,
  	1,0,0,0,23,107,1,0,0,0,25,109,1,0,0,0,27,111,1,0,0,0,29,114,1,0,0,0,31,
  	116,1,0,0,0,33,119,1,0,0,0,35,121,1,0,0,0,37,124,1,0,0,0,39,127,1,0,0,
  	0,41,129,1,0,0,0,43,131,1,0,0,0,45,133,1,0,0,0,47,136,1,0,0,0,49,139,
  	1,0,0,0,51,142,1,0,0,0,53,152,1,0,0,0,55,154,1,0,0,0,57,170,1,0,0,0,59,
  	172,1,0,0,0,61,179,1,0,0,0,63,183,1,0,0,0,65,187,1,0,0,0,67,196,1,0,0,
  	0,69,204,1,0,0,0,71,213,1,0,0,0,73,215,1,0,0,0,75,222,1,0,0,0,77,231,
  	1,0,0,0,79,243,1,0,0,0,81,251,1,0,0,0,83,84,5,105,0,0,84,85,5,102,0,0,
  	85,2,1,0,0,0,86,87,5,37,0,0,87,88,5,61,0,0,88,4,1,0,0,0,89,90,5,40,0,
  	0,90,6,1,0,0,0,91,92,5,41,0,0,92,8,1,0,0,0,93,94,5,123,0,0,94,10,1,0,
  	0,0,95,96,5,125,0,0,96,12,1,0,0,0,97,98,5,91,0,0,98,14,1,0,0,0,99,100,
  	5,93,0,0,100,16,1,0,0,0,101,102,5,43,0,0,102,18,1,0,0,0,103,104,5,45,
  	0,0,104,20,1,0,0,0,105,106,5,42,0,0,106,22,1,0,0,0,107,108,5,47,0,0,108,
  	24,1,0,0,0,109,110,5,37,0,0,110,26,1,0,0,0,111,112,5,61,0,0,112,113,5,
  	61,0,0,113,28,1,0,0,0,114,115,5,62,0,0,115,30,1,0,0,0,116,117,5,62,0,
  	0,117,118,5,61,0,0,118,32,1,0,0,0,119,120,5,60,0,0,120,34,1,0,0,0,121,
  	122,5,60,0,0,122,123,5,61,0,0,123,36,1,0,0,0,124,125,5,58,0,0,125,126,
  	5,58,0,0,126,38,1,0,0,0,127,128,5,59,0,0,128,40,1,0,0,0,129,130,5,44,
  	0,0,130,42,1,0,0,0,131,132,5,61,0,0,132,44,1,0,0,0,133,134,5,43,0,0,134,
  	135,5,61,0,0,135,46,1,0,0,0,136,137,5,45,0,0,137,138,5,61,0,0,138,48,
  	1,0,0,0,139,140,5,42,0,0,140,141,5,61,0,0,141,50,1,0,0,0,142,143,5,47,
  	0,0,143,144,5,61,0,0,144,52,1,0,0,0,145,146,5,108,0,0,146,147,5,111,0,
  	0,147,148,5,111,0,0,148,153,5,112,0,0,149,150,5,12523,0,0,150,151,5,12540,
  	0,0,151,153,5,12503,0,0,152,145,1,0,0,0,152,149,1,0,0,0,153,54,1,0,0,
  	0,154,155,5,119,0,0,155,156,5,104,0,0,156,157,5,105,0,0,157,158,5,108,
  	0,0,158,159,5,101,0,0,159,56,1,0,0,0,160,161,5,98,0,0,161,162,5,114,0,
  	0,162,163,5,101,0,0,163,164,5,97,0,0,164,171,5,107,0,0,165,166,5,12523,
  	0,0,166,167,5,12540,0,0,167,168,5,12503,0,0,168,169,5,20013,0,0,169,171,
  	5,26029,0,0,170,160,1,0,0,0,170,165,1,0,0,0,171,58,1,0,0,0,172,173,5,
  	114,0,0,173,174,5,101,0,0,174,175,5,116,0,0,175,176,5,117,0,0,176,177,
  	5,114,0,0,177,178,5,110,0,0,178,60,1,0,0,0,179,180,5,85,0,0,180,181,5,
  	68,0,0,181,182,5,66,0,0,182,62,1,0,0,0,183,184,5,67,0,0,184,185,5,68,
  	0,0,185,186,5,66,0,0,186,64,1,0,0,0,187,188,5,83,0,0,188,189,5,68,0,0,
  	189,190,5,66,0,0,190,66,1,0,0,0,191,192,5,105,0,0,192,193,5,110,0,0,193,
  	197,5,116,0,0,194,195,5,25972,0,0,195,197,5,25968,0,0,196,191,1,0,0,0,
  	196,194,1,0,0,0,197,68,1,0,0,0,198,199,5,115,0,0,199,200,5,116,0,0,200,
  	205,5,114,0,0,201,202,5,25991,0,0,202,203,5,23383,0,0,203,205,5,21015,
  	0,0,204,198,1,0,0,0,204,201,1,0,0,0,205,70,1,0,0,0,206,207,5,118,0,0,
  	207,208,5,111,0,0,208,209,5,105,0,0,209,214,5,100,0,0,210,211,5,12508,
  	0,0,211,212,5,12452,0,0,212,214,5,12489,0,0,213,206,1,0,0,0,213,210,1,
  	0,0,0,214,72,1,0,0,0,215,219,7,0,0,0,216,218,7,1,0,0,217,216,1,0,0,0,
  	218,221,1,0,0,0,219,217,1,0,0,0,219,220,1,0,0,0,220,74,1,0,0,0,221,219,
  	1,0,0,0,222,226,5,34,0,0,223,225,7,2,0,0,224,223,1,0,0,0,225,228,1,0,
  	0,0,226,224,1,0,0,0,226,227,1,0,0,0,227,229,1,0,0,0,228,226,1,0,0,0,229,
  	230,5,34,0,0,230,76,1,0,0,0,231,232,5,47,0,0,232,233,5,47,0,0,233,237,
  	1,0,0,0,234,236,8,3,0,0,235,234,1,0,0,0,236,239,1,0,0,0,237,235,1,0,0,
  	0,237,238,1,0,0,0,238,240,1,0,0,0,239,237,1,0,0,0,240,241,6,38,0,0,241,
  	78,1,0,0,0,242,244,5,45,0,0,243,242,1,0,0,0,243,244,1,0,0,0,244,246,1,
  	0,0,0,245,247,7,4,0,0,246,245,1,0,0,0,247,248,1,0,0,0,248,246,1,0,0,0,
  	248,249,1,0,0,0,249,80,1,0,0,0,250,252,7,5,0,0,251,250,1,0,0,0,252,253,
  	1,0,0,0,253,251,1,0,0,0,253,254,1,0,0,0,254,255,1,0,0,0,255,256,6,40,
  	0,0,256,82,1,0,0,0,12,0,152,170,196,204,213,219,226,237,243,248,253,1,
  	6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  woditextlexerLexerStaticData = staticData.release();
}

}

woditextLexer::woditextLexer(CharStream *input) : Lexer(input) {
  woditextLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *woditextlexerLexerStaticData->atn, woditextlexerLexerStaticData->decisionToDFA, woditextlexerLexerStaticData->sharedContextCache);
}

woditextLexer::~woditextLexer() {
  delete _interpreter;
}

std::string woditextLexer::getGrammarFileName() const {
  return "woditext.g4";
}

const std::vector<std::string>& woditextLexer::getRuleNames() const {
  return woditextlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& woditextLexer::getChannelNames() const {
  return woditextlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& woditextLexer::getModeNames() const {
  return woditextlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& woditextLexer::getVocabulary() const {
  return woditextlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView woditextLexer::getSerializedATN() const {
  return woditextlexerLexerStaticData->serializedATN;
}

const atn::ATN& woditextLexer::getATN() const {
  return *woditextlexerLexerStaticData->atn;
}




void woditextLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  woditextlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(woditextlexerLexerOnceFlag, woditextlexerLexerInitialize);
#endif
}
