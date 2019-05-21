#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int ln=s.size();
    for(int i=0;i<ln;++i)
    {
        if(s[i]>='A' && s[i]<='Z')
            s[i]=s[i]-'A'+'a';
        if(s[i]=='a' || s[i]=='y' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
        continue;
        else cout<<"."<<s[i];
    }
    return 0;
}
