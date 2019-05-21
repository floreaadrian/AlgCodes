#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;++tt)
    {
        int n,a;
        scanf("%d",&n);
        int f[1005],b[1005];
        for(int i=1;i<=n;++i)
            scanf("%d",&f[i]);
        for(int i=1;i<=n;++i)
            scanf("%d",&b[i]);
        sort(f+1,f+n+1);
        sort(b+1,b+n+1);
        int k=0;
        for(int i=n;i>=1;i--)
        k+=f[i]*b[i];
        printf("%d\n",k);
    }
    return 0;
}
