#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;++tt)
    {
        int n,k1=0,k2=0,a;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a);
            if(i%2==0)
                k1+=a;
            else k2+=a;
        }
        for(int i=1;i<=n;++i){
            scanf("%d",&a);
            if(i%2==0)
                k2+=a;
            else k1+=a;
        }
        printf("%d\n",min(k1,k2));
    }
    return 0;
}
