#include <iostream>
#include <vector>
#include <queue>
#include <pair>

using namespace std;

const int oo = 0x3f3f3f3f;

int n,m,dist[100005];
vector <pair <int,int> > g;

inline void dijkstra(int stnode)
{
    priority_queue <pair <int,int> > q;
    memset(dist,oo,sizeof(dist));
    dist[stnode]=0;
    q.push(make_pair(0,stnode));
    while(!q.empty()){
        int cost=-q.top().first;
        int node=q.top().second;
        q.pop();
        if(dist[node]!=cost)
            continue;
        for(auto it:g[node]){
            if(dist[it.first] > cost + it.second) {
                dist[it.first] = cost + it.second;
                q.push(make_pair(-dist[it.first], it.first));
            }
        }
    }
    for(int i = 2 ; i <= n ; ++ i) {
        if(dist[i] == oo)
            dist[i] = 0;
        fout << dist[i] << ' ';
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    return 0;
}
