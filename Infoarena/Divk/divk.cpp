#include<fstream>
using namespace std;
ifstream fin("divk.in");
ofstream fout("divk.out");
int n,k,a,b,p,v[500005],f[100005];
long long nr;
int main()
{
    int i;
    fin>>n>>k>>a>>b;
    for (i=1;i<=n;++i)
        fin>>v[i], v[i]+=v[i-1], v[i]%=k;
    p=0, f[0]=1;
    for (i=1;i<=n;++i)
    {
        nr+=f[v[i]]++;
        if (i-p>=b) --f[v[p++]];
    }
    for (;p<=n;++p)
        --f[v[p]];
    p=0;
    for (i=0;i<=n;++i)
    {
        nr-=f[v[i]]++;
        if (i-p>=a-1) --f[v[p++]];
    }
    fout<<nr<<"\n";
    return 0;
}
