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
        int n,a[105],ma=0,val[9]={0};
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            {scanf("%d",&a[i]);
        val[a[i]]++;}
        bool ok=true;
        for(int i=1;i<=n/2 && ok;++i)
        {
            if(a[i]!=a[n-i+1]) ok=false;
            if(a[i]!=a[i+1] && a[i]+1!=a[i+1] && a[i]>=8 && a[i]<=0) ok=false;
        }
        for(int i=1;i<=7;++i)
            if(val[i]==0)ok=false;
        if(ok)
        printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
