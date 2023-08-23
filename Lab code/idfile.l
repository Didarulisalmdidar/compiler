%{
    #include<stdio.h>
   int id;
    
%}

%%
[0-9]+[a-zA-Z0-9]* {printf("%s not identifier\n",yytext);}
[a-z][a-zA-Z0-9]* {id++;printf("%s is identifier\n",yytext);}
.|\n {;}

%%
int main()
{
    yyin=fopen("identifiers.txt","r");
    yylex();
    printf("Number of identifiers %d\n",id);
    
    
}
int yywrap()
{
    return 1;
}
