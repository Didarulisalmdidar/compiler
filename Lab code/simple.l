%{
    #include<stdio.h>
    int flag;
%}

%%
and |
but |
or {flag=1;}
.|\n ;


%%
int main()
{

    printf("Enter Expression : ");
    yylex();
    if(flag==1)
        printf("Compound");
    else
        printf("simple");
    
}
int yywrap()
{
    return 1;
}
