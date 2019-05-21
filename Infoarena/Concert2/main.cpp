#include <fstream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

ifstream fin("concert2.in");
ofstream fout("concert2.out");

int n,K1,K2,a[2505],ans,dp[2505][305][305];

int main()
{
fin>>n>>K1>>K2;
for(int i=1;i<=n;++i)
fin>>a[i];
for(int i=1;i<=n;++i)
{
    for(int j=1;j<i;++j)
        for(int k1=1;k1<=K1;++k1)
            for(int k2=1;k2<=K2;++k2)
            {
                if(a[j]<=a[i])
                {
                    dp[i][k1][k2]=max(1+dp[j][k1-1][k2],dp[i][k1][k2]);
                    ans=max(ans,dp[i][k1][k2]);
                }
                if(a[j]>=a[i])
                {
                    dp[i][k1][k2]=max(1+dp[j][k1][k2-1],dp[i][k1][k2]);
                    ans=max(ans,dp[i][k1][k2]);
                }
            }
}
fout<<ans<<'\n';
return 0;
}
