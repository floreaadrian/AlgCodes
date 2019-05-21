#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        int a[10005],s=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        if(s%n!=0) printf("-1\n");
        else {
            int k=0;
            for(int i=1;i<=n;++i)
            if(a[i]>s/n)k+=a[i]-s/n;
            printf("%d\n",k);
        }
        scanf("%d",&n);
    }
    return 0;
}
