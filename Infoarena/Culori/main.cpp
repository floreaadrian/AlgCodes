#include<fstream>
#define MOD 9901
using namespace std;
ifstream f("culori.in");
ofstream g("culori.out");
int n,m,i,j,k,c[600],a[1200][1200];
int main() {
    f>>n;
    m=2*n-1;
    for(i=1; i<=m; ++i)
        {
            f>>c[i];
            a[i][i]=1;
        }
    for(i=1; i<=m; ++i)
        for(j=1; j<=m; ++j)
            if(c[i+j]==c[j])
                for(k=j+1; k<=i+j; ++k) {
                    a[j][i+j]+=(a[j+1][k]*a[k+1][i+j]);
                    a[j][i+j]%=MOD;
                }
    g<<a[1][m]<<'\n';
    return 0;
}
