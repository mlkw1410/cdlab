%{
    #include <stdio.h>
    int yylex();
    void yyerror(char *s);
%}

%token LETTER DIGIT

%%
stmt: var \n       {printf("valid variable"); return 0;}
    ;

var: LETTER rest
    ;

rest: LETTER rest
    | DIGIT rest
    | 
    ;
%%

void yyerror(char *s){
    printf("invalid variable");
}

int main()
{
    printf("enter a variable");
    yywrap();
    return 0;
}