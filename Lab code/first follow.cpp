/*
S->iCtSR
R->eS
R->n
*/

#include<bits/stdc++.h>
using namespace std;
string s[10];
int n;
vector<char>first[10],follow[10];
map<char,int>mp;
map<int,char>mm;
void cal_first(int idx,int cnt)
{
    for(int i=1; i<=n; i++)
    {

        if(s[i][0]==s[idx][0])
        {

            char ch=s[i][2];
            first[cnt].push_back(ch);
        }
    }

}
void process_first(int cnt)
{
//    cout<<"cnt "<<cnt<<endl;
//    for(int i=1;i<=cnt;i++)
//    {
//        for(auto it:first[i])
//            cout<<it<<" ";
//        cout<<endl;
//    }
    for(int i=cnt;i>=1;i--)
    {
        for(int j=0;j<first[i].size();j++)
        {
            if(isupper(first[i][j]))
            {
                first[i].erase(first[i].begin()+j);
                int p=mp[first[i][j]];
                for(auto itt:first[p])
                    first[i].push_back(itt);

            }
        }
    }
    for(int i=1;i<=cnt;i++)
    {
         cout<<"First "<<mm[i]<<" = ";
        for(auto it:first[i]){
                if(isupper(it))
                continue;
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
void cal_follow(int idx,int cnt)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<s[i].size();j++)
        {
            if(s[i][j]==s[idx][0])
            {
                if(j==s[i].size()-1)
                {
                     if(s[i][j]!=s[i][0])
                                follow[cnt].push_back(s[i][0]);
                }

                else if( isupper(s[i][j+1]))
                {
                   // cout<<"else if  "<<mm[cnt]<<" "<<s[i][0]<<" "<<s[i][j+1]<<endl;
                    for(auto it:first[mp[s[i][j+1]]]){
                           // cout<<it<<endl;
                            if(it=='n')
                            {
                                if(s[i][j]!=s[i][0])
                                follow[cnt].push_back(s[i][0]);
                                continue;
                            }
                    else{
                            if(count(follow[cnt].begin(),follow[cnt].end(),it)==0)
                        follow[cnt].push_back(it);
                    }
                    }
                }
                else
                {
                    follow[cnt].push_back(s[i][j+1]);
                }
            }
        }
    }
}
void process_follow(int cnt)
{
   // cout<<"cnt "<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        //cout<<mm[i]<<endl;
         for(int j=0;j<follow[i].size();j++)
        {
            if(isupper(follow[i][j]))
            {
                //cout<<"follow  "<<follow[i][j]<<endl;
                follow[i].erase(follow[i].begin()+j);
                int p=mp[follow[i][j]];
                for(auto itt:follow[p])
                    follow[i].push_back(itt);

            }
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        cout<<"Follow "<<mm[i]<<" = ";
        for(auto it:follow[i]){
                if(isupper(it))
                continue;
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"Enter number of production :";

    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>s[i];
        map<char,int>isDone,isFollow;
        int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(isDone[s[i][0]]==0)
        {
            cnt++;
            mp[s[i][0]]=cnt;
            mm[cnt]=s[i][0];
            cal_first(i,cnt);
            isDone[s[i][0]]=1;
        }
    }
    process_first(cnt);
    int cn=0;
    for(int i=1; i<=n; i++)
    {
        if(isFollow[s[i][0]]==0)
        {
            cn++;
            cal_follow(i,cn);
            isFollow[s[i][0]]=1;
        }

    }
    follow[1].push_back('$');
     process_follow(cn);

}
