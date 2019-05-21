#include <iostream>
#include <vector>
#include <stdio.h>
#include <bitset>
#include <algorithm>
#include <string.h>

using namespace std;

bitset <1000> viz,ap;
vector <int> g[1000];
int disc[1000],low[1000],par[1000],child;

void df(int node,int timp)
{
    viz[node]=true;
    disc[node]=low[node]=timp+1;
    child=0;
    for(auto it: g[node])
        if(!viz[it]){
            child++;
            par[it]=node;
            df(it,timp+1);
            low[node] = min(low[node], low[it]);
            if(par[node]==false && child>1)
                ap[node]=true;
            if(par[node]==true && low[it]>=disc[node])
                ap[node]=true;
        } else if(par[node]!=it)
            low[node]=min(low[node],disc[it]);
}


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    df(1,0);
    for(int i=0;i<n;++i)
        if(ap[i])printf("%d ",i);
    return 0;
}
