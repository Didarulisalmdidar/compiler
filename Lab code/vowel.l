// number of vowel and consonant
%{
    #include<stdio.h>
    int v=0,c=0;
%}

%%
[ \n\t]+ ;
[AEIOUaeiou] {v++;}
[^AEIOUaeiou] {c++;}
%%
int main()
{
    printf("Enter string : ");
    yylex();
    printf("Number of vowel =  %d\n",v);
     printf("Number of consonant =  %d\n",c);

}
int yywrap()
{
    return 1;
}
