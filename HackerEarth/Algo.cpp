#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;++tt)
    {
       long long int a[100005],b[100005];
       int n;
       scanf("%d",&n);
       for(int i=0;i<n;++i)
        scanf("%lli",&a[i]);
       for(int i=0;i<n;++i)
        scanf("%lli",&b[i]);
        bool ok=true;
        int m=0;
       for(int i=0;i<n;i++)
       {
           ok=true;
           for(int j=n-1;j>=i && ok;j--)
           if(a[i]>b[j]) ok=false;
           else m=max(m,j-i);
       }
       printf("%d\n",m);
    }

    return 0;
}
