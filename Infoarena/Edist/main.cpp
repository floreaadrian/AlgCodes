#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

ifstream fin("edist.in");
ofstream fout("edist.out");

char s1[100],s2[100];
int dp[1000][1000];

int eval(int i,int j)
{
    if(s1[i]==s2[j]) return 1;
    return 0;
}

int main()
{
    int n,m,k;
    fin>>n>>m>>k;
    fin>>s1;
    fin>>s2;
    for(int i=1;i<=n;i++)
    dp[i][ 0 ] = dp[ 0 ][i] = i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        dp[i][j] = min(dp[i][j],(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + eval(i, j)) );
    fout<<dp[n][m];
    return 0;
}
