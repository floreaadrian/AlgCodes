#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,a[100005],d;
        long long s=0;
        scanf("%d%d",&n,&d);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        int avg;
        bool ok=true;
        if(s%n==0)avg=s/n;
        else ok=false;
        int ans=0;
        for(int i=0;i<n && ok;++i)
        {
            if(a[i]<avg){
                int pr=avg-a[i];
                ans+=pr;
                a[i+d]-=pr;
            }else if(a[i]>avg){
                int pr=a[i]-avg;
                ans+=pr;
                a[i+d]+=pr;
            }
            if(i+d>n && a[i]!=avg) ok=false;
        }
        if(ok)printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
