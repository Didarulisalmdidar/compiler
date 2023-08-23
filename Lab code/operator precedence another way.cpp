#include<bits/stdc++.h>
using namespace std;
/// E-> (E*E) | E+E | id
int precedenc(char ch)
{
    if(ch=='$')
    return 0;
    if(ch=='(')
        return 1;
    if(ch=='+')
        return 2;
    if(ch=='*')
        return 3;
    if(ch==')')
        return 4;
    if(ch=='d')
        return 5;
}
int main()
{
    cout<<"Enter Expression :";
    string input;
    cin>>input;
    string inp;
    inp="$";
    inp+=input;
    inp+="$";
    cout<<inp<<endl;

        string sec;
        for(int i=0;i<inp.size()-1;i++)
        {
            sec+=inp[i];
            int a=precedenc(inp[i]);
            int b=precedenc(inp[i+1]);
            //cout<<a<<" "<<b<<endl;
            if(a<b)
               sec+="<";
            else
                sec+=">";

        }
        sec+=inp[inp.size()-1];
        cout<<sec<<endl;
        while(1)
        {
            for(int i=0;i<sec.size();i++)
            {
                if(sec[i]=='<' && sec[i+1]=='d')
                {

                    sec.erase(i,3);
                    sec.insert(i,"E");
                }
                else if(sec[i]=='<' && sec[i+1]=='(' && sec[i+5]==')')
                {
                    sec.erase(i,7);
                    sec.insert(i,"E");
                }
                else if(sec[i]=='<' && sec[i+1]=='E' && sec[i+4]=='>')
                {
                    sec.erase(i,5);
                    sec.insert(i,"E");
                }
                else if(sec[i]=='$' && sec[i+1]=='E' && sec[i+4]=='$')
                {
                    sec.erase(i+1,3);
                    sec.insert(i+1,"E");
                }

                //cout<<sec<<endl;

            }
            cout<<sec<<endl;
            if(sec[0]=='$' && sec[2]=='$' && sec[1]=='E'){
                cout<<"Success"<<endl;
                break;
            }
        }

}
