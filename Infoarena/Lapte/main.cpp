#include <fstream>
#include <cstring>
#include <algorithm>
#define nmax 110

using namespace std;
struct date { int x,y; };

int n,k,st,dr,sol;
int dp[nmax][nmax],path[nmax][nmax];
date t[nmax];

ifstream fin("lapte.in");
ofstream fout("lapte.out");

bool ok(int x)
{
    memset(dp,-1,sizeof(dp));
    memset(path,0,sizeof(path));
    dp[0][0]=0;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=k;j++)
            if (dp[i-1][j]>=0) {
                for (int l=0;l+j<=k;l++)
                    if ((x-l*t[i].x)>=0) {
                        if (dp[i][j+l]<dp[i-1][j]+(x-l*t[i].x)/t[i].y) {
                            dp[i][j+l]=dp[i-1][j]+(x-l*t[i].x)/t[i].y;
                            path[i][j+l]=j;
                        }
                    } else break;
            }
    }
    return (dp[n][k]>=k);
}

void findpath(int lv,int x)
{
    if (lv==0) return; else
    {
        findpath(lv-1,path[lv][x]);
        int dif=x-path[lv][x];
        fout<<dif<<" "<<dp[lv][x]-dp[lv-1][path[lv][x]]<<"\n";
    }
}

int main()
{
    fin>>n>>k;
    for (int i=1;i<=n;i++) fin>>t[i].x>>t[i].y;
    st=1; dr=50000;
    while (st<=dr) {
        int m=(st+dr)/2;
        if (ok(m)) {
            sol=m; dr=m-1;
        } else st=m+1;
    }
    ok(sol);
    fout<<sol<<"\n";
    findpath(n,k);
    return 0;
}
