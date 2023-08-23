#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int state=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='b' && state==1)
            state=1;
        else if(s[i]=='a' && state==1)
            state=2;
        else if(s[i]=='b'&& state==2)
            state=3;
        else if(s[i]=='a' && state==2)
            state=2;
        else if(s[i]=='b' && state==3)
            state=4;
        else if(s[i]=='a' && state==3)
            state=2;
        else if(s[i]=='a' && state==4)
            state=2;
        else if(s[i]=='b' && state==4)
            state=1;
        cout<<state<<endl;
    }
    if(state==4)
        cout<<"Accepted"<<endl;
    else
        cout<<"NOT ACCEPTED"<<endl;
}
