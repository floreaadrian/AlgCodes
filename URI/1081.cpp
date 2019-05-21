#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <bitset>

using namespace std;

bool ok=false;
vector <int> g[35];
bitset <35> viz;
int n,m;

void df(int node,int cnt)
{
    cnt+=2;
    viz[node]=true;
    for(auto it: g[node])
    {
        ok=true;
        for(int i=0;i<cnt;i++)printf(" ");
        printf("%d-%d",node,it);
        if(!viz[it]){
            printf(" pathR(G,%d)\n",it);
            df(it,cnt);
        }
        else printf("\n");
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;++k)
    {
        viz.reset();
        memset(g,0,sizeof(g));
        printf("Caso %d:\n",k+1);
        scanf("%d%d",&n,&m);
        ok=false;
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
        }
        for(int i=0;i<n;++i)
        {
            if(!viz[i])
                df(i,0);
            if(ok){
                printf("\n");
                ok=false;
            }
        }
    }
    return 0;
}
