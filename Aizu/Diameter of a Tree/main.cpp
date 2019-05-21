#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector < pair <int,int> > g[100001];
int n,dist[100001],viz[1000001],dmax=0,mnode;

void df(int node)
{
    viz[node]=1;
    int nrn=g[node].size();
    for(int i=0;i<nrn;i++)
    {
        if(!viz[g[node][i].second])
        {
            dist[g[node][i].second]=dist[node]+g[node][i].first;
            if(dist[g[node][i].second]>dmax){
                dmax=dist[g[node][i].second];
                mnode=g[node][i].second;
            }
            df(g[node][i].second);
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(c,b));
        g[b].push_back(make_pair(c,a));
    }
    df(1);
    memset(dist,0,sizeof(dist));
    memset(viz,0,sizeof(viz));
    dmax=0;
    df(mnode);
    cout<<dmax<<"\n";
    return 0;
}
