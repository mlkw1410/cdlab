%{
    #include <stdio.h>
    #include <stdlib.h>
    
    int yylex();
    void yyerror(char *s);
%}


%union
{
    double dval;
}

%token <dval> NUMBER
%type <dval> EXPR

%left '+' '-'
%left '*' '/'
%right UMINUS

%%
stmt: EXPR '\n' {printf("result = %g\n", $1); exit(0);}
    ;
EXPR: EXPR '+' EXPR {$$ = $1 + $3;}
    | EXPR '-' EXPR {$$ = $1 - $3;}
    | EXPR '*' EXPR {$$ = $1 * $3;}
    | EXPR '/' EXPR {
        if ($3 == 0){
            printf("divison by zero");
            exit(0);
        }
        $$ = $1 / $3;
    }
    | '(' EXPR ')' {$$ = $2;}
    | '-' EXPR %prec UMINUS {$$ = -$2;}
    | NUMBER {$$ = $1;}
    ;
%%

void yyerror(char *s)
{
    printf("invalid expression\n");
    exit(1);
}

int main(){
    printf(" enter an expression: ");
    yyparse();
    return 0;
}

