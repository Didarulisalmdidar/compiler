#include<bits/stdc++.h>
using namespace std;
vector<string>keyword{"auto","double","int","struct","break",
    "else","long", "switch","case","enum","register","typedef","char",
    "extern","return","union","const","float","short","unsigned","continue","for",
    "signed","void","default","goto","sizeof","voltile","do","if","static","while"};
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c=='=';
}
bool is_separator(char c)
{
    return c==',' || c==';' ;
}
bool is_Paren(char c)
{
    return c=='(' || c==')';
}
bool is_identifier(string s)
{
    if(isdigit(s[0]))
        return false;
    else
        return true;
}
int main()
{
    string s;
    getline(cin,s);
    int err=0;
    for(int i=0,j=0; j<s.size(); j++)
    {
        string p;
        //cout<<"j "<<s[j]<<endl;
        if(isOperator(s[j]))
        {
            string p;
            for(int k=i;k<j;k++)
                p+=s[k];
           // cout<<p<<" "<<"ok"<<endl;
            i=j+1;
            if(p.size()==1)
            if(isdigit(p[0]))
                continue;
            if(is_identifier(p))
                continue;
                else
                {
                    cout<<"Error"<<endl;
                    err=1;
                    break;
                }

        }
        else if(is_separator(s[j]))
        {
            string p;
            for(int k=i;k<j;k++)
                p+=s[k];
           // cout<<p<<" "<<"ok"<<endl;
            i=j+1;
            if(p.size()==1)
            if(isdigit(p[0]))
                continue;
            if(is_identifier(p))
                continue;
                else
                {
                    cout<<"Error"<<endl;
                    err=1;
                    break;
                }

        }
        else if(s[j]==' ' || s[j]=='(')
        {
            for(int k=i; k<j; k++)
                p+=s[k];
                 //cout<<p<<endl;

            i=j+1;

            if(count(keyword.begin(),keyword.end(),p)==1)
                continue;
            else if(is_identifier(p))
                continue;
            else
            {
                cout<<"Error"<<endl;
                err=1;
                break;
            }
        }
        else if(s[j]==')')
        {
            string p;
            //cout<<i<<" "<<j<<endl;
            for(int k=i;k<j;k++)
            p+=s[k];
            i=j+1;
            // cout<<p<<endl;
            if(p.empty()){
                    //cout<<"space"<<endl;
                continue;
            }
            else if(p[0]=='"' && p[p.size()-1]=='"')
                continue;
            else
            {
                cout<<"Error"<<endl;
                err=1;
                break;
            }


        }
        else if(s[j]=='{')
            {
                i=j+1;
            }
        else if(s[j]=='}')
        {
            string p;
            for(int k=i;k<j;k++)
            p+=s[k];
            //cout<<p<<endl;
            if(!p.empty())
            {
                cout<<"Error"<<endl;
                err=1;
                break;
            }
            i=j+1;
        }
        //cout<<i<<endl;

    }
    if(err==0)
        cout<<"No Error"<<endl;

}
