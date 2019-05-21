#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int max(int a,int b)
{
    if(a>b)return a;
    return b;
}

int a[1025],b[1025],dp[1025][1025],sir[1025],best;

int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;++i)
        fin>>a[i];
    for(int j=1;j<=m;++j)
        fin>>b[j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        if(a[i]==b[j])
        dp[i][j]=1+dp[i-1][j-1];
    else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    int i,j;
    for(i=m,j=n;i;)
        if(a[i]==b[j])
        sir[++best]=a[i],--i,--j;
    else if(dp[i-1][j]<dp[i][j-1])
    j--;
    else i--;
    fout<<best<<"\n";
    for(i=best;i;i--)
        fout<<sir[i]<<" ";
    return 0;
}
