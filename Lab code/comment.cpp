#include <bits/stdc++.h>
using namespace std;
int isComment(string line)
{
    if (line[0] == '/' && line[1] == '/' && line[2] != '/')
    {
        cout << "It is a comment.";
        return 1;
    }
    if (line[line.size() - 2] == '*'&& line[line.size() - 1] == '/' && line[0] == '/' && line[1] == '*')
    {
        cout << "It is a comment.";
        return 1;

    }

    cout << "It is not a comment.";
}
int main()
{
    char line[200];
    cout<<"Enter Comment:";
    gets(line);
    isComment(line);
    return 0;
}
