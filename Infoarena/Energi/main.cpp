#include <fstream>

using namespace std;

ifstream fin("energii.in");
ofstream fout("energii.out");

int g,w,c[1005],e[1005],dp[1005][5005];

int main()
{
    fin>>g>>w;
    for(int i=1;i<=g;i++){
        fin>>e[i]>>c[i];
    }
    for(int i=0;i<=g;i++)
        for(int j=1;j<=w;j++)
        dp[i][j]=(1000000);
    for(int i=1;i<=g;++i){
        for(int j=1;j<=w;j++)
            if(j>=e[i])
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - e[i]] + c[i]);
        else
            dp[i][j] = min(dp[i - 1][j], c[i]);
    }
    if(dp[g][w]==1000000)
        fout<<"-1\n";
    else fout<<dp[g][w];
    return 0;
}
