#include <fstream>
using namespace std;
ifstream f("subsiruri.in");
ofstream g("subsiruri.out");
int v[2000],n,i,j,best[2000],nr[2000],lmax,num;

int main()
{
    f >> n;
    for (i=1; i<=n; i++) f >> v[i];
    for (i=1; i<=n; i++)
    {
        best[i]=1;
        nr[i]=1;
        for (j=1; j<i; j++)
        if (v[j]<v[i] && best[j]+1>best[i])
        {
            best[i]=best[j]+1;
            if (best[i]>lmax) lmax=best[i];
            nr[i]=nr[j];
        } else if (v[j]<v[i] && best[j]+1==best[i]) nr[i]=(nr[i]+nr[j])%9901;
    }
    for (i=1; i<=n; i++) if (best[i]==lmax) num=(num+nr[i])%9901;
    g << lmax << "\n" << num;
}
