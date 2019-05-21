#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int nv[10005];
bool loop;
vector <int> g[10005];

void df(int node)
{
    nv[node]=1;
    int s=g[node].size();
    for(int i=0;i<s && !loop;++i)
        if(nv[g[node][i]]==0)
        df(g[node][i]);
    else if(nv[g[node][i]]==1)
        loop=true;
    nv[node]=2;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(g,0,sizeof(g));
        for(int i=1;i<=m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
        }
        loop=false;
        memset(nv,0,sizeof(nv));
        for(int i=1;i<=n && !loop;++i)
            if(nv[i]!=1)
            df(i);
        if(loop)
            printf("SIM\n");
        else printf("NAO\n");
    }
    return 0;
}
