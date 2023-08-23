%{
    #include<stdio.h>
    int nc;
%}
%%
"/*"[a-zA-Z0-9 \n\t]*"*/" {nc++;}
"//"[a-zA-Z0-9]*"\n" {nc++;};
%%
int main(int argc,char* argv[])
{
    if(argc==2)
    {
        yyin=fopen(argv[1],"r");
    }
    else
    {
        printf("Enter input : \n");
        yyin=stdin;
    }
    yylex();
    printf("number of cmnt %d\n",nc);
}
int yywrap()
{
    return 1;
}