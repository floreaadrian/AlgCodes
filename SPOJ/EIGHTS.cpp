#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main ()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;++tt)
    {
        long long n;
        scanf("%lld",&n);
        long long ans=192+(n-1)*250;
        printf("%lld\n",ans);
    }
    return 0;
}
