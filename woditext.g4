grammar woditext;

// parser
commonlist
    : common* EOF
    ;

common
    : returntype ID '(' params ')' codeblock 
    ;

params
    : paramlist
    |
    ;

paramlist
    : param ',' paramlist
    | param
    ;

param
    : vartype ID
    ;

codeblock
    : '{' stmt* '}'
    ;

ifstmt
    : 'if' '(' expr comp expr ')' codeblock
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
    : LOOP codeblock
    | LOOP '(' expr ')' codeblock
    | WHILE '(' expr ')' codeblock
    ;

stmt
    : stmtcontent ';'
    | loopstmt
    | ifstmt
    | codeblock
    ;

stmtcontent
    : vartype ID        # Decl
    | lhs '=' expr      # Assign
    | lhs '+=' expr     # Assign
    | lhs '-=' expr     # Assign
    | lhs '*=' expr     # Assign
    | lhs '/=' expr     # Assign
    | lhs '%=' expr     # Assign
    | BREAK             # Break
    | RETURN expr       # Return
    ;

comp
    : '==' | '>' | '>=' | '<' | '<='
    ;

call
    : ID '(' args ')'
    ;

args
    : arglist
    |
    ;

arglist
    : expr ',' arglist
    | expr
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
    : '-' expr                          # UnopExpr
    | expr ('*' | '/' | '%') expr       # BinopExpr
    | expr ('+' | '-') expr             # BinopExpr
    | '(' expr ')'                      # ParenExpr
    | call                              # CallExpr
    | ID                                # IdExpr
    | NUM                               # NumExpr
    ;


// lexer
LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';
LBRACK: '[';
RBRACK: ']';

OP_PLUS: '+';
OP_MINUS: '-';
OP_TIMES: '*';
OP_DIV: '/';
OP_MOD: '%';

OP_EQ: '==';
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
RETURN: 'return';

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