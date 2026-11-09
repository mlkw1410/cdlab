%{
    #include <stdio.h>
    int yylex();
    void yyerror(char *s);
%}

%token FOR ID LE GE EQ NE IN DE 

%%
stmt : FOR '(' init ';' cond ';' upd ')'    {printf("valid for statement");
return 0;}
    ;

init : ID = 'exp'
    ;

cond : exp relop exp
    ;

relop : '<' | '>' | LE | GE | NE | EQ 
    ;

upd : ID IN
    | ID DE
    | ID '=' epx
    ;

exp : exp '+' term
    | exp '-' term
    ;

term : ID
    | NUMBER
    ;

%%

void yyerror(char *s){
    printf("invalid statement");
}

int main(){
    printf("enter a valid for statement);
    yyparse();
    return 0;
}