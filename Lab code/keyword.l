//lex program to identify and display keyword , number and word
%{
#include<stdio.h>
%}
%%
if |
else |
for |
while |
printf {printf("%s is a keyword\n ",yytext);}
[0-9]+ {printf("%s is a number\n",yytext);}
[a-zA-Z]+ {printf("%s is a word\n",yytext);}
.|\n {ECHO;}
%%
int main()
{
printf("Enter String : ");
yylex();
}
int yywrap()
{
return 1;
}