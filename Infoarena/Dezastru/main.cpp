#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("dezastru.in");
ofstream fout("dezastru.out");

double a[30][30],p[30];
int n,k;

int main()
{
    fin>>n>>k;
    for(int i=1;i<=n;i++)
        fin>>p[i];
    for(int i=0;i<=n;i++)
        a[i][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            a[i][j]=(a[i-1][j]*(i-j)+a[i-1][j-1]*p[i]*j)/i;
    fout<<fixed<<setprecision(6)<<a[n][k];
    return 0;
}
