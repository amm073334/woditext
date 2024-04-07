grammar woditext;

@parser::header {
#include "src/symboltable.hpp"
}

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
    | BREAK             # Break
    | CONTINUE          # Continue
    | RETURN expr?      # Return
    ;

lhs
    : decl
    | var
    | dbaccess          
    ;

decl
locals [VarSymbol* vs = nullptr]
    : vartype ID
    ;

var
locals [VarSymbol* vs = nullptr]
    : ID
    ;

dbaccess
    : (UDB | CDB | SDB) '[' expr ']' '[' expr ']' '[' expr ']'
    ;

call
locals [CommonSymbol* cs = nullptr]
    : ID '(' (expr (',' expr)*)? ')'
    ;

expr
// apparently, using locals is somewhat frowned upon, but it seems useful for
// getting different code generation depending on expression type
locals [wod_type wt = t_error]
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
    | STRING                                # StringLit
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

STRING: '"' ~["]* '"' {setText(getText().substr(1, getText().size() - 2));};

COMMENT: '//' ~[\r\n]* -> skip;

NUM : '-'?([0-9]+ | '0'('x'|'X')[0-9a-fA-F]+) ;
WS : [ \t\r\n]+ -> skip;