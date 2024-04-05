grammar woditext;

// parser
commonlist
    : common* EOF
    ;

common
    : returntype ID '(' (param (',' param)*)? ')' codeblock 
    ;

param
    : vartype ID
    ;

codeblock
    : '{' stmt* '}'
    ;

ifstmt
    : 'if' '(' expr ')' stmt ('else' stmt)?
    ;

returntype
    : T_VOID
    | T_INT
    | T_STR
    ;

vartype
    : T_INT
    | T_STR
    ;

loopstmt
    : LOOP stmt                    # ForeverLoop
    | LOOP '(' expr ')' stmt       # CountLoop
    | WHILE '(' expr ')' stmt      # WhileLoop
    ;

stmt
    : linestmt ';'
    | loopstmt
    | ifstmt
    | codeblock
    ;

linestmt
    : decl              # DeclStmt
    | call              # CallStmt
    | lhs '=' expr      # Assign
    | lhs '+=' expr     # Assign
    | lhs '-=' expr     # Assign
    | lhs '*=' expr     # Assign
    | lhs '/=' expr     # Assign
    | lhs '%=' expr     # Assign
    | lhs '=' STRING    # StringAssign
    | lhs '+=' STRING   # StringAssign
    | BREAK             # Break
    | CONTINUE          # Continue
    | RETURN expr?      # Return
    | RETURN STRING     # StringReturn
    ;

lhs
    : decl              # DeclLhs
    | var               # VarLhs
    | dbaccess          # DbLhs
    ;

var
    : ID
    ;

decl
    : vartype ID
    ;

dbaccess
    : (UDB | CDB | SDB) '[' expr_or_str ']' '[' expr_or_str ']' '[' expr_or_str ']'
    ;

call
    : ID '(' (expr_or_str (',' expr_or_str)*)? ')'
    ;

expr_or_str
    : expr | STRING
    ;

expr
    : call                                  # CallExpr
    | dbaccess                              # DBExpr
    | '-' expr                              # UnaryMinusExpr
    | '!' expr                              # LogicalNotExpr
    | expr ('*' | '/' | '%') expr           # BinopExpr
    | expr ('+' | '-') expr                 # BinopExpr
    | expr ('<' | '<=' | '>' | '>=') expr   # BinopRelExpr
    | expr ('==' | '!=') expr               # BinopRelEqExpr
    | expr ('&') expr                       # BinopExpr
    | '(' expr ')'                          # ParenExpr
    | var                                   # VarExpr
    | NUM                                   # NumLit
    | (TRUE | FALSE)                        # BoolLit
    ;


// lexer

OP_PLUS: '+';
OP_MINUS: '-';
OP_TIMES: '*';
OP_DIV: '/';
OP_MOD: '%';
OP_AMP: '&';

OP_EQ: '==';
OP_NEQ: '!=';
OP_GT: '>';
OP_GTE: '>=';
OP_LT: '<';
OP_LTE: '<=';

NAMESPACE_SPECIFIER: '::';
SEMICOLON: ';';
COMMA: ',';

AS_EQ: '=';
AS_PEQ: '+=';
AS_MEQ: '-=';
AS_TEQ: '*=';
AS_DEQ: '/=';

LOOP: 'loop' | 'ループ';
WHILE: 'while';
BREAK: 'break' | 'ループ中断';
CONTINUE: 'continue' | 'ループ開始へ';
RETURN: 'return';

TRUE: 'true';
FALSE: 'false';

UDB: 'UDB';
CDB: 'CDB';
SDB: 'SDB';

T_INT: 'int' | '整数' ;
T_STR: 'str' | '文字列' ;
T_VOID: 'void' | 'ボイド';

ID: [_\p{Alpha}\p{General_Category=Other_Letter}][_\p{Alnum}\p{General_Category=Other_Letter}]*;

STRING: '"' ~["]* '"';

COMMENT: '//' ~[\r\n]* -> skip;

NUM : '-'?([0-9]+ | '0'('x'|'X')[0-9a-fA-F]+) ;
WS : [ \t\r\n]+ -> skip;