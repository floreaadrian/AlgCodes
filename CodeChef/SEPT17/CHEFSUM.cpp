#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,a[100005],suf[100005]={0},pre[100005]={0};
        scanf("%lli",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%lli",&a[i]);
            suf[i]=suf[i-1]+a[i];
        }
        int loc=0;
        long long mi=LONG_MAX;
        for(int i=n;i>=1;--i)
        {
            pre[i]=pre[i+1]+a[i];
        }
        for(int i=1;i<=n;++i)
        if(suf[i]+pre[i]<mi)
        {
            mi=suf[i]+pre[i];
            loc=i;
        }
        printf("%d\n",loc);
    }
    return 0;
}
