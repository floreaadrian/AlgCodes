#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("politie.in");
ofstream fout("politie.out");

int n,m,i,D,p,r,sol[1<<18],GR[1<<18];
struct pt{
    int a,b,c,d;
}v[1<<19];

inline int gr(int i)
{
    if(GR[i]==i) return i;
    GR[i]=gr(GR[i]);
    return GR[i];
}
inline void unite(int i,int j)
{
    GR[gr(i)]=gr(j);
}
struct cmp
{
    bool operator() (pt x,pt y)
    {
        if(x.c==y.c) return x.d<y.d;
        return x.c<y.c;
    }
};
int main()
{
    fin>>n>>m>>D>>p;
    for(i=1;i<=n;++i) GR[i]=i;
    for(i=1;i<=m;++i)
        fin>>v[i].a>>v[i].b>>v[i].c>>v[i].d;
    sort(v+1,v+m+1,cmp());
    for(i=1;i<=m;++i)
        if(gr(v[i].a)!=gr(v[i].b))
    {
        unite(v[i].a,v[i].b);
        sol[++r]=v[i].d;
    }
    sort(sol+1,sol+r+1);
    while(p)
    {
        if(sol[r]!=sol[r+1])
        {
            fout<<sol[r]<<'\n';
            --p;
        }
        --r;
    }
    return 0;
}
