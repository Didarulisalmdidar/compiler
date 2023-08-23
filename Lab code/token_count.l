%{
    #include<stdio.h>
    int tc;
%}

%%
int|float|char|string {tc++;}
if|else|for|while {tc++;}
[a-zA-Z][a-zA-Z0-9]* {tc++;}
[0-9]+ {tc++;}
[(){}|, ;] {tc++;}
"<="|"=="|">="|"<"|">"|"+"|"-"|"*"|"/" {tc++;}


%%
int main()
{
    printf("Enter input : ");
    yylex();
    printf("number of token : %d \n",tc);
    
}
int yywrap()
{
    return 1;
}