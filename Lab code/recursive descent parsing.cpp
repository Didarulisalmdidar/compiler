/*
Write a C program to construct recursive descent parsing for the following grammar:
E->TE'
E'->+TE'|N
T->FT'
T`->*FT'| N
F->(E)| id
id ( a-z)
Where N is a null character
i+i*i
*/

#include<bits/stdc++.h>
using namespace std;
void E();
void Epr();
void T();
void Tpr();
void F();
string input;
int error=0,i=0;
int main()
{
    cout<<"Enter an Expression : ";
    cin>>input;
    E();
    if(i==input.size() && error==0)
        cout<<"String is Accepted"<<endl;
    else
        cout<<"Not Accepted"<<endl;

}
void E()
{
    T();
    Epr();
}
void T()
{
    F();
    Tpr();
}
void Epr()
{
    if(input[i]=='+')
    {
        i++;
        T();
        Epr();
    }
}
void Tpr()
{
    if(input[i]=='*')
    {
        i++;
        F();
        Tpr();
    }
}
void F()
{
    if(input[i]>='a' && input[i]<='z')
    {
        i++;
    }
    else if(input[i]=='(')
    {
        i++;
        E();
        if(input[i]==')')
            i++;
        else
            error=1;
    }
    else
        error=1;

}
