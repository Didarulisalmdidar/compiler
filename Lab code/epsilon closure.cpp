#include<bits/stdc++.h>
using namespace std;
vector<char>v[100];
bool is_visit[100];
void dfs(char ch)
{
    cout<<ch<<" ";
    is_visit[ch]=true;
    for(auto it: v[ch])
    {
        if(!is_visit[it]){
        dfs(it);
        }
    }
    cout<<endl;
}
int main()
{
    cout<<"No of states : ";
    int n;
    cin>>n;
    char st[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>st[i];
    }
    cout<<"No of Edges : ";
    int edg;
    cin>>edg;
    while(edg--)
    {
        //int a,c;
        char a,b,c;
        cin>>a>>b>>c;
        if(b=='e')
            v[a].push_back(c);

    }
    for(int i=1;i<=n;i++)
    {
        cout<<"Epsilon closure of "<<st[i]<<" :";
       memset(is_visit,false,sizeof(is_visit));
       dfs(st[i]);
    }
}
