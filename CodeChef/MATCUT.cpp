#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

long long mare=0;
int cst[100005],d;
vector <int> g[100005];
bool viz[100005];

bool cube(long long n)
{
    int root(round(cbrt(n)));
    return n == root * root * root;
}

void df(int node,long long cost,int& dr)
{
    if(!viz[node]) viz[node]=true;
    for(auto it: g[node])
    {
        if(!viz[it])
        {
            cost*=cst[it];
            d++;
            if(cube(cost)){
            dr=d;
            mare=max(cost,mare);
            }
            df(it,cost,dr);
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;++tt)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",cst[i]);
        for(int i=1;i<n;++i)
        {
            int x,y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        memset(cst,0,sizeof(cst));
        mare=0;
        int dr=0;
        for(int i=1;i<=n;++i)
        {
            d=0;
            memset(viz,false,sizeof(viz));
            df(i,0,dr);
        }
        if(dr==0)printf("-1\n");
        printf("%d\n",dr);
    }
}
