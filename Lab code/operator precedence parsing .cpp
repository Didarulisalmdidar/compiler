#include<bits/stdc++.h>
using namespace std;
/// E-> E+E | E*E | id
string stk="$";
string ip;
int precedenc(char ch)
{
    if(ch=='$')
    return 0;
    if(ch==')')
        return 1;
    if(ch=='+')
        return 2;
    if(ch=='*')
        return 3;
    if(ch=='(')
        return 4;
    if(ch=='i')
        return 5;
}
int main()
{
    stack<char>st;
    stack<char>inp;
    string input;
    cin>>input;
    ip=input;
    ip+='$';
    inp.push('$');
    st.push('$');
    for(int i=input.size()-1;i>=0;i--)
        inp.push(input[i]);
    cout<<"stack    "<<"Input    "<<"Action"<<endl;
    while(1)
    {

        cout<<stk<<"        "<<ip<<"   ";
        char c1=st.top();
        char c2=inp.top();
        if(c1=='$' && c2=='$')
        {
            cout<<"Accepted"<<endl;
            break;
        }
        int a=precedenc(c1);
        int b=precedenc(c2);
        if(b>a)
        {
            inp.pop();
            ip.erase(0,1);
            st.push(c2);
            stk+=c2;
            cout<<"push  "<<c2<<endl;
        }
        else
        {
            cout<<"pop  "<<c1<<endl;
            st.pop();
            stk.erase(stk.size()-1,1);

        }

    }

}
