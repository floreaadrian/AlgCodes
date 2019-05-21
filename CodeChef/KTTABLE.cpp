#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int a[10005],b[10005],n,t;
    cin>>t;
    a[0]=0;
    while(t--)
    {
        int c=0;
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=1;i<=n;++i)
            cin>>b[i];
        for(int i=1;i<=n;++i)
            if((a[i]-a[i-1])>=b[i])
                c++;
        cout<<c<<"\n";
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
    return 0;
}
