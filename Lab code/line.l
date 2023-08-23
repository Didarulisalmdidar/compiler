%{
    #include<stdio.h>
    int lc=0,wc=0,cc=0,sc=0;
%}

%%
[\n] {lc++;cc+=yyleng;}
[ \t] {sc++;cc+=yyleng;}
[^\n\t ]+ {wc++;cc+=yyleng;}// until encounter a space newline tab it is a word
%%
int main()
{
    printf("Enter string : ");
    yylex();
    printf("Number of line =  %d\n",lc);
     printf("Number of word =  %d\n",wc);
      printf("Number of space =  %d\n",sc);
 printf("Number of character =  %d\n",cc);

}
int yywrap()
{
    return 1;
}
