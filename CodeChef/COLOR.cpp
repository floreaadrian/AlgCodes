#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,r=0,g=0,b=0;
        char s[100005];
        cin>>n;
        cin>>s;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='R')r++;
            else if(s[i]=='B')b++;
            else if(s[i]=='G')g++;
        }
        cout<<n-max(r,max(g,b))<<"\n";
    }
    return 0;
}
