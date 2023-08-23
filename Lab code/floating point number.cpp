#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int state=12;
    for(int i=0; i<s.size(); i++)
    {
        if(isdigit(s[i])&& state==12)
            state=13;
        else if(isdigit(s[i])&& state==13)
            state=13;
        else if(s[i]=='.' && state==13)
            state==14;
        else if(s[i]=='E' && state==13)
            state=16;
        else if(isdigit(s[i]) && state==14)
            state=15;
        else if(isdigit(s[i]) && state==15)
            state=15;
        else if(s[i]=='E' && state==15)
            state=16;
        else if((s[i]=='+' || s[i]=='-') && state==16)
            state=17;
        else if(isdigit(s[i]) && (state==16 || state==17))
            state=18;
        else if(isdigit(s[i])&& state==18)
            state=18;


    }
    if(state==13 || state==15 || state==18)
        cout<<"Accepted"<<endl;
    else
        cout<<"Rejected"<<endl;
}
