#include <cstdio>

using namespace std;

int n,i,j;
long long phi[100005],x;

int main()
{
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    scanf("%d",&n);
    for(i = 1; i <= 100000; ++i)
        phi[i] = i-1;
    for(i = 2; i <= 100000; ++i)
        for(j = 2*i; j <= 100000; j += i)
            phi[j] -= phi[i];
    for(i = 1; i <= n; ++i)
    {
        scanf("%d",&x);
        printf("%lld\n",x * 2 * phi[x]);
    }
    return 0;
}
