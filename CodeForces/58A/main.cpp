#include <iostream>
#include <string.h>

using namespace std;

char A[]="hello";

int main()
{
    char s[101];
    int n,a=0;
    cin>>s;
    n=strlen(s);
    for(int i=0;i<n;++i)
        if(A[a]==s[i])a++;
    if(a==5)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
