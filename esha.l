%{
    #include <stdio.h>

    int flag=1;
%}

%%
[eE][sS][hH][aA]    {flag =0; }
\n  {return 0;}
.   ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("enter string");

    yylex();

    if (flag == 1)
    {
        printf("string sccpeted");
    }

    else
    {
        printf("string rejected");
    }
}