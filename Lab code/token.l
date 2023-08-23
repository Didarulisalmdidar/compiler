%{
    #include<stdio.h>
%}

%%
int printf("%s keyword\n",yytext);
[a-zA-Z]+ printf("%s Identifier\n",yytext);
[0-9]+ printf("%s digit\n",yytext);
[=] printf("%s assignment\n",yytext);
[+] printf("%s plus\n",yytext);
[;] printf("%s semicolon\n",yytext);


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
