#include <bits/stdc++.h>

using namespace std;

bitset <100005> viz;
int nivel[100005],n,val[100005];
vector <int> g[100005];
vector < pair <int,int> > ni[100005];

void df(int nod)
{
    viz[nod]=1;
    for(auto it: g[nod])
    if(viz[it]==0){
        nivel[it]=nivel[nod]+1,ni[nivel[it]].push_back(make_pair(it,nod));
        df(it);
    }
}

bool caut(int n1,int n2,int root)
{
    int k=nivel[n1],ac;
    while(k!=n2)
        {
            k=nivel[ni[k].second];
            ac=ni[k].second;
        }
    if(ac==root)
        return true;
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;++tt)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            scanf("%d",&val[i]);
        for(int i=1;i<n;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        nivel[1]=1;
        df(1);
        for(int j=0;j<m;++j)
        {
            int k,kr;
            long long s=0;
            scanf("%d%d",&k,&kr);
            for(auto it: ni[kr])
                if(caut(it.first,nivel[kr],kr))
                    s+=val[it.first];
            printf("%lli\n",s);
        }
        memset(ni,0,sizeof(ni));
        memset(g,0,sizeof(g));
        memset(nivel,0,sizeof(nivel));
        viz.reset();
    }
    return 0;
}
