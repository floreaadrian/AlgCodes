#include <bits/stdc++>

using namespace std;

void tr(char c)
{
    char l;
    if(c>='a' && c<='z')
    {
        l=c-'a'+'A';
    }else l=c-'A'+'a';
    cout<<l;
}

int main()
{
    string s;
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;++i)
        tr(s[i]);
    return 0;
}
