%{
    #include<stdio.h>
    int pn,nn,pf,nf;
%}

%%
[0-9]+ {pn++;}
[-][0-9]+ {nn++;}
[0-9]+[.][0-9]+ {pf++;}
[-][0-9]+[.][0-9]+ {nf++;}


%%
int main()
{
    printf("Enter input : ");
    yylex();
    printf("Positive number %d : \n",pn);
    printf("Negative number %d : \n",nn);
     printf("Positive fraction number %d : \n",pf);
      printf("Negative fraction number %d : \n",nf);
}
int yywrap()
{
    return 1;
}