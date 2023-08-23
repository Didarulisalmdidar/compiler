%{ 
#include <stdio.h> 
#include <string.h> 
    int operators_count = 0, operands_count = 0, valid = 1, top = -1, i = 0, j = 0,k=0; 
    char operands[10][10], operators[10][10], stack[100]; 
%} 
%%
"(" {top++;stack[top]=')';}
")" { 
if(stack[top]!='(')
{ 
valid=0;
}
else
{
top--;
}
}

"+"|"-"|"*"|"/" { 
    operators_count++; 
    strcpy(operators[i], yytext); 
    i++; 
} 
[0-9]+|[a-zA-z][a-zA-Z0-9]* { 
    operands_count++; 
    strcpy(operands[j], yytext); 
    j++; 
} 
.|\n {return 0;}
%% 
  
  
 
int main() 
{ 
    printf("Enter the arithmetic expression: "); 
    yylex(); 
  
    if (operands_count-operators_count==1) { 
        printf("\nValid Expression\n"); 
printf("OPerators are : \n");



    for( k=0;k<i;k++)
     {
        printf("%s\n",operators[k]);
      }
printf("OPerands are : \n");
for( k=0;k<j;k++)
     {
        printf("%s\n",operands[k]);
      }
    } 
    else
        printf("\nInvalid Expression\n"); 
  
    return 0;
} 
int yywrap() 
{ 
    return 1; 
}