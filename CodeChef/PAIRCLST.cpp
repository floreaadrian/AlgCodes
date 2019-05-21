#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

const int maxn = 100005;
const int oo = 0x3f3f3f3f;

int n, m, dist[maxn],v[maxn],mi,k;
vector <pair<int, int> > g[maxn];

inline void dijkstra(int stnode) {
    priority_queue <pair<int, int> > q;
    memset(dist, oo, sizeof(dist));
    dist[stnode] = 0;
    q.push(make_pair(0, stnode));
    while(!q.empty()) {
        int cost = -q.top().first;
        int node = q.top().second;
        q.pop();
        if(dist[node] != cost)
            continue;
        for(auto it : g[node]) {
            if(dist[it.first] > cost + it.second) {
                dist[it.first] = cost + it.second;
                q.push(make_pair(-dist[it.first], it.first));
            }
        }
    }
    for(int i=1;i<=k;++i)
        if(v[i]!=stnode)
        mi=min(mi,dist[v[i]]);
}

int main() {
    cin >> n >> m >> k;
    for(int i = 1 ; i <= k ; ++ i)
        cin >> v[i];
    for(int i = 1 ; i <= m ; ++ i) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }
    mi=oo;
    for(int i=1;i<k;++i)
    dijkstra(v[i]);
    cout<<mi;
    return 0;
}
