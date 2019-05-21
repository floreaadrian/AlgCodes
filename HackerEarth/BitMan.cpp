#include <iostream>
#include <stdio.h>
#define mod 1000000007
using namespace std;

long long lm[100005];

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;++tt)
    {
        long long n,s=0;
        scanf("%lli",&n);
        if(!lm[n])
        for(long long i=3;i<=n;++i)
        {
            int c=0,k=i;
            while(k && c<3)
            {
                k=k&(k-1);
                c++;
            }
            if(c==2)s=(s+i)%mod;
            lm[i]=s;
        }else
        s=lm[n];
        printf("%lli\n",s);
    }
}
