#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        char k[12346];
        cin>>s;
        bool ok=true;
        int l=s.size();
        for(int i=0;i<l;++i)
        if(s[i]=='.' || s[l-i-1]=='.'){
            if(s[l-i-1]=='.' && s[i]=='.')s[i]=s[l-i-1]=(char)'a';
            else if(s[i]=='.') s[i]=s[l-i-1];
            else s[l-i-1]=s[i];
        }else if(s[i]!=s[l-i-1]) ok=false;
        if(ok)
            cout<<s<<"\n";
            else cout<<"-1\n";
    }
    return 0;
}
