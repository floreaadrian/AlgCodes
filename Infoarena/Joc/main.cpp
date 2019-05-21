#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

const int oo = 0x3f3f3f3f;
const int maxn = 1005;

int max(int a,int b)
{
    if(a>b)return a;
    return b;
}

int dp[maxn][maxn],a[maxn][maxn];

ifstream fin("joc.in");
ofstream fout("joc.out");

int main()
{
    int n,m;
    fin>>n>>m;
    memset(dp,-oo,sizeof(dp));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            fin>>a[i][j];
    dp[1][1]=a[1][1];
    fin.close();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(i==1 && j==1)
            continue;
            a[i][j]-=max(dp[i-1][j],dp[i][j-1]);
            dp[i][j]=max(a[i][j],max(dp[i-1][j],dp[i][j-1]));
        }
    a[0][0]=-oo;
    pair <int,int> ans = make_pair(0,0);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        if(a[ans.first][ans.second]<a[i][j])
            ans = make_pair(i,j);
    fout<<a[ans.first][ans.second]<<" "<<ans.first<<" "<<ans.second;
    fout.close();
    return 0;
}
