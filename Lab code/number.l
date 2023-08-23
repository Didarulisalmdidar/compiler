%{
    #include<stdio.h>
%}

%%
[0-9]+[.][0-9]+[E][-]?[0-9]* {printf("%s is Exponential floating point number\n",yytext);}
[0-9]+ {printf("%s is integer\n",yytext);}
[0-9]+[.][0-9]+ {printf("%s is floating point number\n",yytext);}
.+ {printf("others");}
%%
int main()
{
    printf("Enter input : ");
    yylex();
}
int yywrap()
{
    return 1;
}