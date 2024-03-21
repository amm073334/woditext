// Generated from ../woditext.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class woditextParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, LPAREN=3, RPAREN=4, LBRACE=5, RBRACE=6, LBRACK=7, RBRACK=8, 
		OP_PLUS=9, OP_MINUS=10, OP_TIMES=11, OP_DIV=12, OP_MOD=13, OP_EQ=14, OP_GT=15, 
		OP_GTE=16, OP_LT=17, OP_LTE=18, NAMESPACE_SPECIFIER=19, SEMICOLON=20, 
		COMMA=21, AS_EQ=22, AS_PEQ=23, AS_MEQ=24, AS_TEQ=25, AS_DEQ=26, LOOP=27, 
		WHILE=28, BREAK=29, RETURN=30, UDB=31, CDB=32, SDB=33, T_INT=34, T_STR=35, 
		T_VOID=36, ID=37, STRING=38, COMMENT=39, NUM=40, WS=41;
	public static final int
		RULE_commonlist = 0, RULE_common = 1, RULE_params = 2, RULE_paramlist = 3, 
		RULE_param = 4, RULE_codeblock = 5, RULE_ifstmt = 6, RULE_returntype = 7, 
		RULE_vartype = 8, RULE_loopstmt = 9, RULE_stmt = 10, RULE_stmtcontent = 11, 
		RULE_comp = 12, RULE_call = 13, RULE_args = 14, RULE_arglist = 15, RULE_lhs = 16, 
		RULE_dbaccess = 17, RULE_dbattr = 18, RULE_expr = 19;
	private static String[] makeRuleNames() {
		return new String[] {
			"commonlist", "common", "params", "paramlist", "param", "codeblock", 
			"ifstmt", "returntype", "vartype", "loopstmt", "stmt", "stmtcontent", 
			"comp", "call", "args", "arglist", "lhs", "dbaccess", "dbattr", "expr"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'if'", "'%='", "'('", "')'", "'{'", "'}'", "'['", "']'", "'+'", 
			"'-'", "'*'", "'/'", "'%'", "'=='", "'>'", "'>='", "'<'", "'<='", "'::'", 
			"';'", "','", "'='", "'+='", "'-='", "'*='", "'/='", null, "'while'", 
			null, "'return'", "'UDB'", "'CDB'", "'SDB'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", 
			"OP_PLUS", "OP_MINUS", "OP_TIMES", "OP_DIV", "OP_MOD", "OP_EQ", "OP_GT", 
			"OP_GTE", "OP_LT", "OP_LTE", "NAMESPACE_SPECIFIER", "SEMICOLON", "COMMA", 
			"AS_EQ", "AS_PEQ", "AS_MEQ", "AS_TEQ", "AS_DEQ", "LOOP", "WHILE", "BREAK", 
			"RETURN", "UDB", "CDB", "SDB", "T_INT", "T_STR", "T_VOID", "ID", "STRING", 
			"COMMENT", "NUM", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "woditext.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public woditextParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CommonlistContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(woditextParser.EOF, 0); }
		public List<CommonContext> common() {
			return getRuleContexts(CommonContext.class);
		}
		public CommonContext common(int i) {
			return getRuleContext(CommonContext.class,i);
		}
		public CommonlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_commonlist; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterCommonlist(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitCommonlist(this);
		}
	}

	public final CommonlistContext commonlist() throws RecognitionException {
		CommonlistContext _localctx = new CommonlistContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_commonlist);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(43);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 120259084288L) != 0)) {
				{
				{
				setState(40);
				common();
				}
				}
				setState(45);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(46);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CommonContext extends ParserRuleContext {
		public ReturntypeContext returntype() {
			return getRuleContext(ReturntypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(woditextParser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(woditextParser.LPAREN, 0); }
		public ParamsContext params() {
			return getRuleContext(ParamsContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(woditextParser.RPAREN, 0); }
		public CodeblockContext codeblock() {
			return getRuleContext(CodeblockContext.class,0);
		}
		public CommonContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_common; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterCommon(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitCommon(this);
		}
	}

	public final CommonContext common() throws RecognitionException {
		CommonContext _localctx = new CommonContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_common);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(48);
			returntype();
			setState(49);
			match(ID);
			setState(50);
			match(LPAREN);
			setState(51);
			params();
			setState(52);
			match(RPAREN);
			setState(53);
			codeblock();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParamsContext extends ParserRuleContext {
		public ParamlistContext paramlist() {
			return getRuleContext(ParamlistContext.class,0);
		}
		public ParamsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_params; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterParams(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitParams(this);
		}
	}

	public final ParamsContext params() throws RecognitionException {
		ParamsContext _localctx = new ParamsContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_params);
		try {
			setState(57);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T_INT:
			case T_STR:
				enterOuterAlt(_localctx, 1);
				{
				setState(55);
				paramlist();
				}
				break;
			case RPAREN:
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParamlistContext extends ParserRuleContext {
		public ParamContext param() {
			return getRuleContext(ParamContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(woditextParser.COMMA, 0); }
		public ParamlistContext paramlist() {
			return getRuleContext(ParamlistContext.class,0);
		}
		public ParamlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_paramlist; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterParamlist(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitParamlist(this);
		}
	}

	public final ParamlistContext paramlist() throws RecognitionException {
		ParamlistContext _localctx = new ParamlistContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_paramlist);
		try {
			setState(64);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(59);
				param();
				setState(60);
				match(COMMA);
				setState(61);
				paramlist();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(63);
				param();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParamContext extends ParserRuleContext {
		public VartypeContext vartype() {
			return getRuleContext(VartypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(woditextParser.ID, 0); }
		public ParamContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_param; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterParam(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitParam(this);
		}
	}

	public final ParamContext param() throws RecognitionException {
		ParamContext _localctx = new ParamContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_param);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(66);
			vartype();
			setState(67);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CodeblockContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(woditextParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(woditextParser.RBRACE, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public CodeblockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_codeblock; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterCodeblock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitCodeblock(this);
		}
	}

	public final CodeblockContext codeblock() throws RecognitionException {
		CodeblockContext _localctx = new CodeblockContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_codeblock);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(69);
			match(LBRACE);
			setState(73);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 190991826978L) != 0)) {
				{
				{
				setState(70);
				stmt();
				}
				}
				setState(75);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(76);
			match(RBRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IfstmtContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(woditextParser.LPAREN, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public CompContext comp() {
			return getRuleContext(CompContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(woditextParser.RPAREN, 0); }
		public CodeblockContext codeblock() {
			return getRuleContext(CodeblockContext.class,0);
		}
		public IfstmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifstmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterIfstmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitIfstmt(this);
		}
	}

	public final IfstmtContext ifstmt() throws RecognitionException {
		IfstmtContext _localctx = new IfstmtContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_ifstmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(78);
			match(T__0);
			setState(79);
			match(LPAREN);
			setState(80);
			expr(0);
			setState(81);
			comp();
			setState(82);
			expr(0);
			setState(83);
			match(RPAREN);
			setState(84);
			codeblock();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ReturntypeContext extends ParserRuleContext {
		public TerminalNode T_VOID() { return getToken(woditextParser.T_VOID, 0); }
		public TerminalNode T_INT() { return getToken(woditextParser.T_INT, 0); }
		public TerminalNode T_STR() { return getToken(woditextParser.T_STR, 0); }
		public ReturntypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_returntype; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterReturntype(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitReturntype(this);
		}
	}

	public final ReturntypeContext returntype() throws RecognitionException {
		ReturntypeContext _localctx = new ReturntypeContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_returntype);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(86);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 120259084288L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VartypeContext extends ParserRuleContext {
		public TerminalNode T_INT() { return getToken(woditextParser.T_INT, 0); }
		public TerminalNode T_STR() { return getToken(woditextParser.T_STR, 0); }
		public VartypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vartype; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterVartype(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitVartype(this);
		}
	}

	public final VartypeContext vartype() throws RecognitionException {
		VartypeContext _localctx = new VartypeContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_vartype);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(88);
			_la = _input.LA(1);
			if ( !(_la==T_INT || _la==T_STR) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LoopstmtContext extends ParserRuleContext {
		public TerminalNode LOOP() { return getToken(woditextParser.LOOP, 0); }
		public CodeblockContext codeblock() {
			return getRuleContext(CodeblockContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(woditextParser.LPAREN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(woditextParser.RPAREN, 0); }
		public TerminalNode WHILE() { return getToken(woditextParser.WHILE, 0); }
		public LoopstmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_loopstmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterLoopstmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitLoopstmt(this);
		}
	}

	public final LoopstmtContext loopstmt() throws RecognitionException {
		LoopstmtContext _localctx = new LoopstmtContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_loopstmt);
		try {
			setState(104);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(90);
				match(LOOP);
				setState(91);
				codeblock();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(92);
				match(LOOP);
				setState(93);
				match(LPAREN);
				setState(94);
				expr(0);
				setState(95);
				match(RPAREN);
				setState(96);
				codeblock();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(98);
				match(WHILE);
				setState(99);
				match(LPAREN);
				setState(100);
				expr(0);
				setState(101);
				match(RPAREN);
				setState(102);
				codeblock();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StmtContext extends ParserRuleContext {
		public StmtcontentContext stmtcontent() {
			return getRuleContext(StmtcontentContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(woditextParser.SEMICOLON, 0); }
		public LoopstmtContext loopstmt() {
			return getRuleContext(LoopstmtContext.class,0);
		}
		public IfstmtContext ifstmt() {
			return getRuleContext(IfstmtContext.class,0);
		}
		public CodeblockContext codeblock() {
			return getRuleContext(CodeblockContext.class,0);
		}
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterStmt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitStmt(this);
		}
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_stmt);
		try {
			setState(112);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BREAK:
			case RETURN:
			case T_INT:
			case T_STR:
			case ID:
				enterOuterAlt(_localctx, 1);
				{
				setState(106);
				stmtcontent();
				setState(107);
				match(SEMICOLON);
				}
				break;
			case LOOP:
			case WHILE:
				enterOuterAlt(_localctx, 2);
				{
				setState(109);
				loopstmt();
				}
				break;
			case T__0:
				enterOuterAlt(_localctx, 3);
				{
				setState(110);
				ifstmt();
				}
				break;
			case LBRACE:
				enterOuterAlt(_localctx, 4);
				{
				setState(111);
				codeblock();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StmtcontentContext extends ParserRuleContext {
		public StmtcontentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmtcontent; }
	 
		public StmtcontentContext() { }
		public void copyFrom(StmtcontentContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ReturnContext extends StmtcontentContext {
		public TerminalNode RETURN() { return getToken(woditextParser.RETURN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ReturnContext(StmtcontentContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterReturn(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitReturn(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BreakContext extends StmtcontentContext {
		public TerminalNode BREAK() { return getToken(woditextParser.BREAK, 0); }
		public BreakContext(StmtcontentContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterBreak(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitBreak(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DeclContext extends StmtcontentContext {
		public VartypeContext vartype() {
			return getRuleContext(VartypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(woditextParser.ID, 0); }
		public DeclContext(StmtcontentContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterDecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitDecl(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AssignContext extends StmtcontentContext {
		public LhsContext lhs() {
			return getRuleContext(LhsContext.class,0);
		}
		public TerminalNode AS_EQ() { return getToken(woditextParser.AS_EQ, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode AS_PEQ() { return getToken(woditextParser.AS_PEQ, 0); }
		public TerminalNode AS_MEQ() { return getToken(woditextParser.AS_MEQ, 0); }
		public TerminalNode AS_TEQ() { return getToken(woditextParser.AS_TEQ, 0); }
		public TerminalNode AS_DEQ() { return getToken(woditextParser.AS_DEQ, 0); }
		public AssignContext(StmtcontentContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterAssign(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitAssign(this);
		}
	}

	public final StmtcontentContext stmtcontent() throws RecognitionException {
		StmtcontentContext _localctx = new StmtcontentContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_stmtcontent);
		try {
			setState(144);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				_localctx = new DeclContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(114);
				vartype();
				setState(115);
				match(ID);
				}
				break;
			case 2:
				_localctx = new AssignContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(117);
				lhs();
				setState(118);
				match(AS_EQ);
				setState(119);
				expr(0);
				}
				break;
			case 3:
				_localctx = new AssignContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(121);
				lhs();
				setState(122);
				match(AS_PEQ);
				setState(123);
				expr(0);
				}
				break;
			case 4:
				_localctx = new AssignContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(125);
				lhs();
				setState(126);
				match(AS_MEQ);
				setState(127);
				expr(0);
				}
				break;
			case 5:
				_localctx = new AssignContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(129);
				lhs();
				setState(130);
				match(AS_TEQ);
				setState(131);
				expr(0);
				}
				break;
			case 6:
				_localctx = new AssignContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(133);
				lhs();
				setState(134);
				match(AS_DEQ);
				setState(135);
				expr(0);
				}
				break;
			case 7:
				_localctx = new AssignContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(137);
				lhs();
				setState(138);
				match(T__1);
				setState(139);
				expr(0);
				}
				break;
			case 8:
				_localctx = new BreakContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(141);
				match(BREAK);
				}
				break;
			case 9:
				_localctx = new ReturnContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(142);
				match(RETURN);
				setState(143);
				expr(0);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CompContext extends ParserRuleContext {
		public TerminalNode OP_EQ() { return getToken(woditextParser.OP_EQ, 0); }
		public TerminalNode OP_GT() { return getToken(woditextParser.OP_GT, 0); }
		public TerminalNode OP_GTE() { return getToken(woditextParser.OP_GTE, 0); }
		public TerminalNode OP_LT() { return getToken(woditextParser.OP_LT, 0); }
		public TerminalNode OP_LTE() { return getToken(woditextParser.OP_LTE, 0); }
		public CompContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_comp; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterComp(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitComp(this);
		}
	}

	public final CompContext comp() throws RecognitionException {
		CompContext _localctx = new CompContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_comp);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(146);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 507904L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CallContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(woditextParser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(woditextParser.LPAREN, 0); }
		public ArgsContext args() {
			return getRuleContext(ArgsContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(woditextParser.RPAREN, 0); }
		public CallContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_call; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterCall(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitCall(this);
		}
	}

	public final CallContext call() throws RecognitionException {
		CallContext _localctx = new CallContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_call);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(148);
			match(ID);
			setState(149);
			match(LPAREN);
			setState(150);
			args();
			setState(151);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgsContext extends ParserRuleContext {
		public ArglistContext arglist() {
			return getRuleContext(ArglistContext.class,0);
		}
		public ArgsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_args; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterArgs(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitArgs(this);
		}
	}

	public final ArgsContext args() throws RecognitionException {
		ArgsContext _localctx = new ArgsContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_args);
		try {
			setState(155);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
			case OP_MINUS:
			case ID:
			case NUM:
				enterOuterAlt(_localctx, 1);
				{
				setState(153);
				arglist();
				}
				break;
			case RPAREN:
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArglistContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(woditextParser.COMMA, 0); }
		public ArglistContext arglist() {
			return getRuleContext(ArglistContext.class,0);
		}
		public ArglistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arglist; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterArglist(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitArglist(this);
		}
	}

	public final ArglistContext arglist() throws RecognitionException {
		ArglistContext _localctx = new ArglistContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_arglist);
		try {
			setState(162);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(157);
				expr(0);
				setState(158);
				match(COMMA);
				setState(159);
				arglist();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(161);
				expr(0);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LhsContext extends ParserRuleContext {
		public VartypeContext vartype() {
			return getRuleContext(VartypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(woditextParser.ID, 0); }
		public LhsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lhs; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterLhs(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitLhs(this);
		}
	}

	public final LhsContext lhs() throws RecognitionException {
		LhsContext _localctx = new LhsContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_lhs);
		try {
			setState(168);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T_INT:
			case T_STR:
				enterOuterAlt(_localctx, 1);
				{
				setState(164);
				vartype();
				setState(165);
				match(ID);
				}
				break;
			case ID:
				enterOuterAlt(_localctx, 2);
				{
				setState(167);
				match(ID);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DbaccessContext extends ParserRuleContext {
		public List<DbattrContext> dbattr() {
			return getRuleContexts(DbattrContext.class);
		}
		public DbattrContext dbattr(int i) {
			return getRuleContext(DbattrContext.class,i);
		}
		public TerminalNode UDB() { return getToken(woditextParser.UDB, 0); }
		public TerminalNode CDB() { return getToken(woditextParser.CDB, 0); }
		public TerminalNode SDB() { return getToken(woditextParser.SDB, 0); }
		public DbaccessContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_dbaccess; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterDbaccess(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitDbaccess(this);
		}
	}

	public final DbaccessContext dbaccess() throws RecognitionException {
		DbaccessContext _localctx = new DbaccessContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_dbaccess);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(170);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 15032385536L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(171);
			dbattr();
			setState(172);
			dbattr();
			setState(173);
			dbattr();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DbattrContext extends ParserRuleContext {
		public TerminalNode LBRACK() { return getToken(woditextParser.LBRACK, 0); }
		public TerminalNode RBRACK() { return getToken(woditextParser.RBRACK, 0); }
		public TerminalNode NUM() { return getToken(woditextParser.NUM, 0); }
		public TerminalNode STRING() { return getToken(woditextParser.STRING, 0); }
		public DbattrContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_dbattr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterDbattr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitDbattr(this);
		}
	}

	public final DbattrContext dbattr() throws RecognitionException {
		DbattrContext _localctx = new DbattrContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_dbattr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(175);
			match(LBRACK);
			setState(176);
			_la = _input.LA(1);
			if ( !(_la==STRING || _la==NUM) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(177);
			match(RBRACK);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class IdExprContext extends ExprContext {
		public TerminalNode ID() { return getToken(woditextParser.ID, 0); }
		public IdExprContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterIdExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitIdExpr(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NumExprContext extends ExprContext {
		public TerminalNode NUM() { return getToken(woditextParser.NUM, 0); }
		public NumExprContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterNumExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitNumExpr(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UnopExprContext extends ExprContext {
		public TerminalNode OP_MINUS() { return getToken(woditextParser.OP_MINUS, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public UnopExprContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterUnopExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitUnopExpr(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CallExprContext extends ExprContext {
		public CallContext call() {
			return getRuleContext(CallContext.class,0);
		}
		public CallExprContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterCallExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitCallExpr(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParenExprContext extends ExprContext {
		public TerminalNode LPAREN() { return getToken(woditextParser.LPAREN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(woditextParser.RPAREN, 0); }
		public ParenExprContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterParenExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitParenExpr(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BinopExprContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode OP_TIMES() { return getToken(woditextParser.OP_TIMES, 0); }
		public TerminalNode OP_DIV() { return getToken(woditextParser.OP_DIV, 0); }
		public TerminalNode OP_MOD() { return getToken(woditextParser.OP_MOD, 0); }
		public TerminalNode OP_PLUS() { return getToken(woditextParser.OP_PLUS, 0); }
		public TerminalNode OP_MINUS() { return getToken(woditextParser.OP_MINUS, 0); }
		public BinopExprContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).enterBinopExpr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof woditextListener ) ((woditextListener)listener).exitBinopExpr(this);
		}
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 38;
		enterRecursionRule(_localctx, 38, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(189);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				{
				_localctx = new UnopExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(180);
				match(OP_MINUS);
				setState(181);
				expr(7);
				}
				break;
			case 2:
				{
				_localctx = new ParenExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(182);
				match(LPAREN);
				setState(183);
				expr(0);
				setState(184);
				match(RPAREN);
				}
				break;
			case 3:
				{
				_localctx = new CallExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(186);
				call();
				}
				break;
			case 4:
				{
				_localctx = new IdExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(187);
				match(ID);
				}
				break;
			case 5:
				{
				_localctx = new NumExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(188);
				match(NUM);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(199);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(197);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
					case 1:
						{
						_localctx = new BinopExprContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(191);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(192);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 14336L) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(193);
						expr(7);
						}
						break;
					case 2:
						{
						_localctx = new BinopExprContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(194);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(195);
						_la = _input.LA(1);
						if ( !(_la==OP_PLUS || _la==OP_MINUS) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(196);
						expr(6);
						}
						break;
					}
					} 
				}
				setState(201);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 19:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 6);
		case 1:
			return precpred(_ctx, 5);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001)\u00cb\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0001\u0000\u0005\u0000*\b\u0000\n\u0000\f\u0000"+
		"-\t\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002"+
		"\u0003\u0002:\b\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0003\u0003A\b\u0003\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0005\u0001\u0005\u0005\u0005H\b\u0005\n\u0005\f\u0005K\t\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007"+
		"\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0003\ti\b"+
		"\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0003\nq\b\n\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003"+
		"\u000b\u0091\b\u000b\u0001\f\u0001\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\u000e\u0001\u000e\u0003\u000e\u009c\b\u000e\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u00a3\b\u000f\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0003\u0010\u00a9\b\u0010\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0003\u0013\u00be\b\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0005\u0013\u00c6\b\u0013\n\u0013\f\u0013"+
		"\u00c9\t\u0013\u0001\u0013\u0000\u0001&\u0014\u0000\u0002\u0004\u0006"+
		"\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&\u0000"+
		"\u0007\u0001\u0000\"$\u0001\u0000\"#\u0001\u0000\u000e\u0012\u0001\u0000"+
		"\u001f!\u0002\u0000&&((\u0001\u0000\u000b\r\u0001\u0000\t\n\u00d0\u0000"+
		"+\u0001\u0000\u0000\u0000\u00020\u0001\u0000\u0000\u0000\u00049\u0001"+
		"\u0000\u0000\u0000\u0006@\u0001\u0000\u0000\u0000\bB\u0001\u0000\u0000"+
		"\u0000\nE\u0001\u0000\u0000\u0000\fN\u0001\u0000\u0000\u0000\u000eV\u0001"+
		"\u0000\u0000\u0000\u0010X\u0001\u0000\u0000\u0000\u0012h\u0001\u0000\u0000"+
		"\u0000\u0014p\u0001\u0000\u0000\u0000\u0016\u0090\u0001\u0000\u0000\u0000"+
		"\u0018\u0092\u0001\u0000\u0000\u0000\u001a\u0094\u0001\u0000\u0000\u0000"+
		"\u001c\u009b\u0001\u0000\u0000\u0000\u001e\u00a2\u0001\u0000\u0000\u0000"+
		" \u00a8\u0001\u0000\u0000\u0000\"\u00aa\u0001\u0000\u0000\u0000$\u00af"+
		"\u0001\u0000\u0000\u0000&\u00bd\u0001\u0000\u0000\u0000(*\u0003\u0002"+
		"\u0001\u0000)(\u0001\u0000\u0000\u0000*-\u0001\u0000\u0000\u0000+)\u0001"+
		"\u0000\u0000\u0000+,\u0001\u0000\u0000\u0000,.\u0001\u0000\u0000\u0000"+
		"-+\u0001\u0000\u0000\u0000./\u0005\u0000\u0000\u0001/\u0001\u0001\u0000"+
		"\u0000\u000001\u0003\u000e\u0007\u000012\u0005%\u0000\u000023\u0005\u0003"+
		"\u0000\u000034\u0003\u0004\u0002\u000045\u0005\u0004\u0000\u000056\u0003"+
		"\n\u0005\u00006\u0003\u0001\u0000\u0000\u00007:\u0003\u0006\u0003\u0000"+
		"8:\u0001\u0000\u0000\u000097\u0001\u0000\u0000\u000098\u0001\u0000\u0000"+
		"\u0000:\u0005\u0001\u0000\u0000\u0000;<\u0003\b\u0004\u0000<=\u0005\u0015"+
		"\u0000\u0000=>\u0003\u0006\u0003\u0000>A\u0001\u0000\u0000\u0000?A\u0003"+
		"\b\u0004\u0000@;\u0001\u0000\u0000\u0000@?\u0001\u0000\u0000\u0000A\u0007"+
		"\u0001\u0000\u0000\u0000BC\u0003\u0010\b\u0000CD\u0005%\u0000\u0000D\t"+
		"\u0001\u0000\u0000\u0000EI\u0005\u0005\u0000\u0000FH\u0003\u0014\n\u0000"+
		"GF\u0001\u0000\u0000\u0000HK\u0001\u0000\u0000\u0000IG\u0001\u0000\u0000"+
		"\u0000IJ\u0001\u0000\u0000\u0000JL\u0001\u0000\u0000\u0000KI\u0001\u0000"+
		"\u0000\u0000LM\u0005\u0006\u0000\u0000M\u000b\u0001\u0000\u0000\u0000"+
		"NO\u0005\u0001\u0000\u0000OP\u0005\u0003\u0000\u0000PQ\u0003&\u0013\u0000"+
		"QR\u0003\u0018\f\u0000RS\u0003&\u0013\u0000ST\u0005\u0004\u0000\u0000"+
		"TU\u0003\n\u0005\u0000U\r\u0001\u0000\u0000\u0000VW\u0007\u0000\u0000"+
		"\u0000W\u000f\u0001\u0000\u0000\u0000XY\u0007\u0001\u0000\u0000Y\u0011"+
		"\u0001\u0000\u0000\u0000Z[\u0005\u001b\u0000\u0000[i\u0003\n\u0005\u0000"+
		"\\]\u0005\u001b\u0000\u0000]^\u0005\u0003\u0000\u0000^_\u0003&\u0013\u0000"+
		"_`\u0005\u0004\u0000\u0000`a\u0003\n\u0005\u0000ai\u0001\u0000\u0000\u0000"+
		"bc\u0005\u001c\u0000\u0000cd\u0005\u0003\u0000\u0000de\u0003&\u0013\u0000"+
		"ef\u0005\u0004\u0000\u0000fg\u0003\n\u0005\u0000gi\u0001\u0000\u0000\u0000"+
		"hZ\u0001\u0000\u0000\u0000h\\\u0001\u0000\u0000\u0000hb\u0001\u0000\u0000"+
		"\u0000i\u0013\u0001\u0000\u0000\u0000jk\u0003\u0016\u000b\u0000kl\u0005"+
		"\u0014\u0000\u0000lq\u0001\u0000\u0000\u0000mq\u0003\u0012\t\u0000nq\u0003"+
		"\f\u0006\u0000oq\u0003\n\u0005\u0000pj\u0001\u0000\u0000\u0000pm\u0001"+
		"\u0000\u0000\u0000pn\u0001\u0000\u0000\u0000po\u0001\u0000\u0000\u0000"+
		"q\u0015\u0001\u0000\u0000\u0000rs\u0003\u0010\b\u0000st\u0005%\u0000\u0000"+
		"t\u0091\u0001\u0000\u0000\u0000uv\u0003 \u0010\u0000vw\u0005\u0016\u0000"+
		"\u0000wx\u0003&\u0013\u0000x\u0091\u0001\u0000\u0000\u0000yz\u0003 \u0010"+
		"\u0000z{\u0005\u0017\u0000\u0000{|\u0003&\u0013\u0000|\u0091\u0001\u0000"+
		"\u0000\u0000}~\u0003 \u0010\u0000~\u007f\u0005\u0018\u0000\u0000\u007f"+
		"\u0080\u0003&\u0013\u0000\u0080\u0091\u0001\u0000\u0000\u0000\u0081\u0082"+
		"\u0003 \u0010\u0000\u0082\u0083\u0005\u0019\u0000\u0000\u0083\u0084\u0003"+
		"&\u0013\u0000\u0084\u0091\u0001\u0000\u0000\u0000\u0085\u0086\u0003 \u0010"+
		"\u0000\u0086\u0087\u0005\u001a\u0000\u0000\u0087\u0088\u0003&\u0013\u0000"+
		"\u0088\u0091\u0001\u0000\u0000\u0000\u0089\u008a\u0003 \u0010\u0000\u008a"+
		"\u008b\u0005\u0002\u0000\u0000\u008b\u008c\u0003&\u0013\u0000\u008c\u0091"+
		"\u0001\u0000\u0000\u0000\u008d\u0091\u0005\u001d\u0000\u0000\u008e\u008f"+
		"\u0005\u001e\u0000\u0000\u008f\u0091\u0003&\u0013\u0000\u0090r\u0001\u0000"+
		"\u0000\u0000\u0090u\u0001\u0000\u0000\u0000\u0090y\u0001\u0000\u0000\u0000"+
		"\u0090}\u0001\u0000\u0000\u0000\u0090\u0081\u0001\u0000\u0000\u0000\u0090"+
		"\u0085\u0001\u0000\u0000\u0000\u0090\u0089\u0001\u0000\u0000\u0000\u0090"+
		"\u008d\u0001\u0000\u0000\u0000\u0090\u008e\u0001\u0000\u0000\u0000\u0091"+
		"\u0017\u0001\u0000\u0000\u0000\u0092\u0093\u0007\u0002\u0000\u0000\u0093"+
		"\u0019\u0001\u0000\u0000\u0000\u0094\u0095\u0005%\u0000\u0000\u0095\u0096"+
		"\u0005\u0003\u0000\u0000\u0096\u0097\u0003\u001c\u000e\u0000\u0097\u0098"+
		"\u0005\u0004\u0000\u0000\u0098\u001b\u0001\u0000\u0000\u0000\u0099\u009c"+
		"\u0003\u001e\u000f\u0000\u009a\u009c\u0001\u0000\u0000\u0000\u009b\u0099"+
		"\u0001\u0000\u0000\u0000\u009b\u009a\u0001\u0000\u0000\u0000\u009c\u001d"+
		"\u0001\u0000\u0000\u0000\u009d\u009e\u0003&\u0013\u0000\u009e\u009f\u0005"+
		"\u0015\u0000\u0000\u009f\u00a0\u0003\u001e\u000f\u0000\u00a0\u00a3\u0001"+
		"\u0000\u0000\u0000\u00a1\u00a3\u0003&\u0013\u0000\u00a2\u009d\u0001\u0000"+
		"\u0000\u0000\u00a2\u00a1\u0001\u0000\u0000\u0000\u00a3\u001f\u0001\u0000"+
		"\u0000\u0000\u00a4\u00a5\u0003\u0010\b\u0000\u00a5\u00a6\u0005%\u0000"+
		"\u0000\u00a6\u00a9\u0001\u0000\u0000\u0000\u00a7\u00a9\u0005%\u0000\u0000"+
		"\u00a8\u00a4\u0001\u0000\u0000\u0000\u00a8\u00a7\u0001\u0000\u0000\u0000"+
		"\u00a9!\u0001\u0000\u0000\u0000\u00aa\u00ab\u0007\u0003\u0000\u0000\u00ab"+
		"\u00ac\u0003$\u0012\u0000\u00ac\u00ad\u0003$\u0012\u0000\u00ad\u00ae\u0003"+
		"$\u0012\u0000\u00ae#\u0001\u0000\u0000\u0000\u00af\u00b0\u0005\u0007\u0000"+
		"\u0000\u00b0\u00b1\u0007\u0004\u0000\u0000\u00b1\u00b2\u0005\b\u0000\u0000"+
		"\u00b2%\u0001\u0000\u0000\u0000\u00b3\u00b4\u0006\u0013\uffff\uffff\u0000"+
		"\u00b4\u00b5\u0005\n\u0000\u0000\u00b5\u00be\u0003&\u0013\u0007\u00b6"+
		"\u00b7\u0005\u0003\u0000\u0000\u00b7\u00b8\u0003&\u0013\u0000\u00b8\u00b9"+
		"\u0005\u0004\u0000\u0000\u00b9\u00be\u0001\u0000\u0000\u0000\u00ba\u00be"+
		"\u0003\u001a\r\u0000\u00bb\u00be\u0005%\u0000\u0000\u00bc\u00be\u0005"+
		"(\u0000\u0000\u00bd\u00b3\u0001\u0000\u0000\u0000\u00bd\u00b6\u0001\u0000"+
		"\u0000\u0000\u00bd\u00ba\u0001\u0000\u0000\u0000\u00bd\u00bb\u0001\u0000"+
		"\u0000\u0000\u00bd\u00bc\u0001\u0000\u0000\u0000\u00be\u00c7\u0001\u0000"+
		"\u0000\u0000\u00bf\u00c0\n\u0006\u0000\u0000\u00c0\u00c1\u0007\u0005\u0000"+
		"\u0000\u00c1\u00c6\u0003&\u0013\u0007\u00c2\u00c3\n\u0005\u0000\u0000"+
		"\u00c3\u00c4\u0007\u0006\u0000\u0000\u00c4\u00c6\u0003&\u0013\u0006\u00c5"+
		"\u00bf\u0001\u0000\u0000\u0000\u00c5\u00c2\u0001\u0000\u0000\u0000\u00c6"+
		"\u00c9\u0001\u0000\u0000\u0000\u00c7\u00c5\u0001\u0000\u0000\u0000\u00c7"+
		"\u00c8\u0001\u0000\u0000\u0000\u00c8\'\u0001\u0000\u0000\u0000\u00c9\u00c7"+
		"\u0001\u0000\u0000\u0000\r+9@Ihp\u0090\u009b\u00a2\u00a8\u00bd\u00c5\u00c7";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}