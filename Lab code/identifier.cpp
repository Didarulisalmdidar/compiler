#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string>keyword{"auto","double","int","struct","break",
                          "else","long", "switch","case","enum","register","typedef","char",
                          "extern","return","union","const","float","short","unsigned","continue","for",
                          "signed","void","default","goto","sizeof","voltile","do","if","static","while"};
    cout<<"Enter Identifier : ";
    string input;
    cin>>input;
    if(count(keyword.begin(),keyword.end(),input)!=0)
        cout<<"INVALID IDENTIFIER"<<endl;
    else
    {
        if(isalpha(input[0]) || input[0]=='_')
        {
            cout<<"VALID IDENTIFIER"<<endl;
        }
        else
            cout<<"INVALID IDENTIFIER"<<endl;
    }

}
