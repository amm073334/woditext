
// Generated from woditext.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  woditextLexer : public antlr4::Lexer {
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

  explicit woditextLexer(antlr4::CharStream *input);

  ~woditextLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

