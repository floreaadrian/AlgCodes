#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
 
using namespace std;
 
const int maxn = 50005;
const int oo = 0x3f3f3f3f;
 
int n, m, dist[maxn];
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
            int nr=g[node].size();
        for(int i=0;i<nr;i++) {
            if(dist[g[node][i].first] > cost + g[node][i].second) {
                dist[g[node][i].first] = cost + g[node][i].second;
                q.push(make_pair(-dist[g[node][i].first], g[node][i].first));
            }
        }
    }
}
 
int main() {
	int nr,start,fin;
	cin>>nr;
	while(nr--)
	{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; ++ i) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
    }
    cin>>start>>fin;
    dijkstra(start);
    memset(g, 0, sizeof(g));
    if(dist[fin]!=oo)
    cout<<dist[fin]<<"\n";
    else cout<<"NO\n";
 	}
}
