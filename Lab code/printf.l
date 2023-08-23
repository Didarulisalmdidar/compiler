%{
    #include<stdio.h>
    int pf,sf;
%}

%%
"printf" {pf++;fprintf(yyout,"readf");}
"scanf" {sf++;fprintf(yyout,"writef");}

%%
int main()
{
   
    yyin=fopen("sp.txt","r");
    yyout=fopen("new2.txt","w");
    yylex();
    printf("Number of scanf : %d\n",sf);
    printf("Number of printf : %d\n",pf);
    
    
}
int yywrap()
{
    return 1;
}
