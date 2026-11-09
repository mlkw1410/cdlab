%{
    #include "y.tab.h"
%}

%%
"for"   return FOR;
[a-z A-Z][a-z A-Z 0-9]*     return ID;
[0-9]+      return NUMBER;
"<="    return LE;
">="    return GE;
"=="    return EQ;
"!="    return NE;
"++"    return IN;
"--"    return DE;
[ \t\n] ;
.       return yytext[0];
%%

int yywrap(){
    return 1;
}

