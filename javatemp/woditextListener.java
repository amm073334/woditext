// Generated from ../woditext.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link woditextParser}.
 */
public interface woditextListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link woditextParser#commonlist}.
	 * @param ctx the parse tree
	 */
	void enterCommonlist(woditextParser.CommonlistContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#commonlist}.
	 * @param ctx the parse tree
	 */
	void exitCommonlist(woditextParser.CommonlistContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#common}.
	 * @param ctx the parse tree
	 */
	void enterCommon(woditextParser.CommonContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#common}.
	 * @param ctx the parse tree
	 */
	void exitCommon(woditextParser.CommonContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#params}.
	 * @param ctx the parse tree
	 */
	void enterParams(woditextParser.ParamsContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#params}.
	 * @param ctx the parse tree
	 */
	void exitParams(woditextParser.ParamsContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#paramlist}.
	 * @param ctx the parse tree
	 */
	void enterParamlist(woditextParser.ParamlistContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#paramlist}.
	 * @param ctx the parse tree
	 */
	void exitParamlist(woditextParser.ParamlistContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#param}.
	 * @param ctx the parse tree
	 */
	void enterParam(woditextParser.ParamContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#param}.
	 * @param ctx the parse tree
	 */
	void exitParam(woditextParser.ParamContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#codeblock}.
	 * @param ctx the parse tree
	 */
	void enterCodeblock(woditextParser.CodeblockContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#codeblock}.
	 * @param ctx the parse tree
	 */
	void exitCodeblock(woditextParser.CodeblockContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#ifstmt}.
	 * @param ctx the parse tree
	 */
	void enterIfstmt(woditextParser.IfstmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#ifstmt}.
	 * @param ctx the parse tree
	 */
	void exitIfstmt(woditextParser.IfstmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#returntype}.
	 * @param ctx the parse tree
	 */
	void enterReturntype(woditextParser.ReturntypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#returntype}.
	 * @param ctx the parse tree
	 */
	void exitReturntype(woditextParser.ReturntypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#vartype}.
	 * @param ctx the parse tree
	 */
	void enterVartype(woditextParser.VartypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#vartype}.
	 * @param ctx the parse tree
	 */
	void exitVartype(woditextParser.VartypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#loopstmt}.
	 * @param ctx the parse tree
	 */
	void enterLoopstmt(woditextParser.LoopstmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#loopstmt}.
	 * @param ctx the parse tree
	 */
	void exitLoopstmt(woditextParser.LoopstmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterStmt(woditextParser.StmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitStmt(woditextParser.StmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Decl}
	 * labeled alternative in {@link woditextParser#stmtcontent}.
	 * @param ctx the parse tree
	 */
	void enterDecl(woditextParser.DeclContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Decl}
	 * labeled alternative in {@link woditextParser#stmtcontent}.
	 * @param ctx the parse tree
	 */
	void exitDecl(woditextParser.DeclContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Assign}
	 * labeled alternative in {@link woditextParser#stmtcontent}.
	 * @param ctx the parse tree
	 */
	void enterAssign(woditextParser.AssignContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Assign}
	 * labeled alternative in {@link woditextParser#stmtcontent}.
	 * @param ctx the parse tree
	 */
	void exitAssign(woditextParser.AssignContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Break}
	 * labeled alternative in {@link woditextParser#stmtcontent}.
	 * @param ctx the parse tree
	 */
	void enterBreak(woditextParser.BreakContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Break}
	 * labeled alternative in {@link woditextParser#stmtcontent}.
	 * @param ctx the parse tree
	 */
	void exitBreak(woditextParser.BreakContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Return}
	 * labeled alternative in {@link woditextParser#stmtcontent}.
	 * @param ctx the parse tree
	 */
	void enterReturn(woditextParser.ReturnContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Return}
	 * labeled alternative in {@link woditextParser#stmtcontent}.
	 * @param ctx the parse tree
	 */
	void exitReturn(woditextParser.ReturnContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#comp}.
	 * @param ctx the parse tree
	 */
	void enterComp(woditextParser.CompContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#comp}.
	 * @param ctx the parse tree
	 */
	void exitComp(woditextParser.CompContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#call}.
	 * @param ctx the parse tree
	 */
	void enterCall(woditextParser.CallContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#call}.
	 * @param ctx the parse tree
	 */
	void exitCall(woditextParser.CallContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#args}.
	 * @param ctx the parse tree
	 */
	void enterArgs(woditextParser.ArgsContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#args}.
	 * @param ctx the parse tree
	 */
	void exitArgs(woditextParser.ArgsContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#arglist}.
	 * @param ctx the parse tree
	 */
	void enterArglist(woditextParser.ArglistContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#arglist}.
	 * @param ctx the parse tree
	 */
	void exitArglist(woditextParser.ArglistContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#lhs}.
	 * @param ctx the parse tree
	 */
	void enterLhs(woditextParser.LhsContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#lhs}.
	 * @param ctx the parse tree
	 */
	void exitLhs(woditextParser.LhsContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#dbaccess}.
	 * @param ctx the parse tree
	 */
	void enterDbaccess(woditextParser.DbaccessContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#dbaccess}.
	 * @param ctx the parse tree
	 */
	void exitDbaccess(woditextParser.DbaccessContext ctx);
	/**
	 * Enter a parse tree produced by {@link woditextParser#dbattr}.
	 * @param ctx the parse tree
	 */
	void enterDbattr(woditextParser.DbattrContext ctx);
	/**
	 * Exit a parse tree produced by {@link woditextParser#dbattr}.
	 * @param ctx the parse tree
	 */
	void exitDbattr(woditextParser.DbattrContext ctx);
	/**
	 * Enter a parse tree produced by the {@code IdExpr}
	 * labeled alternative in {@link woditextParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterIdExpr(woditextParser.IdExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code IdExpr}
	 * labeled alternative in {@link woditextParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitIdExpr(woditextParser.IdExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code NumExpr}
	 * labeled alternative in {@link woditextParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterNumExpr(woditextParser.NumExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code NumExpr}
	 * labeled alternative in {@link woditextParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitNumExpr(woditextParser.NumExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnopExpr}
	 * labeled alternative in {@link woditextParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterUnopExpr(woditextParser.UnopExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnopExpr}
	 * labeled alternative in {@link woditextParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitUnopExpr(woditextParser.UnopExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code CallExpr}
	 * labeled alternative in {@link woditextParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterCallExpr(woditextParser.CallExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code CallExpr}
	 * labeled alternative in {@link woditextParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitCallExpr(woditextParser.CallExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParenExpr}
	 * labeled alternative in {@link woditextParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterParenExpr(woditextParser.ParenExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParenExpr}
	 * labeled alternative in {@link woditextParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitParenExpr(woditextParser.ParenExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BinopExpr}
	 * labeled alternative in {@link woditextParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterBinopExpr(woditextParser.BinopExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinopExpr}
	 * labeled alternative in {@link woditextParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitBinopExpr(woditextParser.BinopExprContext ctx);
}