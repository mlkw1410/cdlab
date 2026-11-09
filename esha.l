%{
    #include <stdio.h>

    int flag=1;
%}                      /* HERE WE DEFINE THE HEADER*/

%%
[eE][sS][hH][aA]    {flag =0; }     /* HERE WE DEFINE THE RULES*/
\n  {return 0;}
.   ;
%%

int yywrap()
{
    return 1;               /* HERE CALLED WHEN LEX REACH THE END OF ITS INPUT*/
}

int main()                  /* HERE WE DEFINE THE MAIN FUNCTION*/
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