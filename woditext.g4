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
    : vartype ID        # Decl
    | lhs '=' expr      # Assign
    | lhs '+=' expr     # Assign
    | lhs '-=' expr     # Assign
    | lhs '*=' expr     # Assign
    | lhs '/=' expr     # Assign
    | lhs '%=' expr     # Assign
    | BREAK             # Break
    | CONTINUE          # Continue
    | RETURN expr?      # Return
    ;

lhs
    : vartype ID
    | ID
    ;

dbaccess
    : (UDB | CDB | SDB) dbattr dbattr dbattr
    ;

dbattr
    : '[' (NUM | STRING) ']'
    ;

expr
    : ID '(' (expr (',' expr)*)? ')'        # CallExpr
    | '-' expr                              # UnaryMinusExpr
    | '!' expr                              # LogicalNotExpr
    | expr ('*' | '/' | '%') expr           # BinopExpr
    | expr ('+' | '-') expr                 # BinopExpr
    | expr ('<' | '<=' | '>' | '>=') expr   # BinopRelExpr
    | expr ('==' | '!=') expr               # BinopRelExpr
    | expr ('&') expr                       # BinopExpr
    | '(' expr ')'                          # ParenExpr
    | ID                                    # IdExpr
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

ID: [_a-zA-Z][_a-zA-Z0-9]*;

STRING: '"' [^"]* '"';

COMMENT: '//' ~[\r\n]* -> skip;

NUM : '-'?[0-9]+ ;
WS : [ \t\r\n]+ -> skip;