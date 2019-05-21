#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
 
using namespace std;

const int maxn = 100000;
const int oo = 0x3f3f3f3f;
 
int n, m, dist[maxn],S,D,dist1[maxn];
vector <pair<int, int> > g[maxn];
vector <pair<int, int> > g1[maxn];

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

inline void dijkstra1(int stnode) {
    priority_queue <pair<int, int> > q;
    memset(dist1, oo, sizeof(dist1));
    dist1[stnode] = 0;
    q.push(make_pair(0, stnode));
    while(!q.empty()) {
        int cost = -q.top().first;
        int node = q.top().second;
        q.pop();
        if(dist1[node] != cost)
            continue;
            int nr=g1[node].size();
        for(int i=0;i<nr;i++) {
            if(dist1[g1[node][i].first] > cost + g1[node][i].second) {
                dist1[g1[node][i].first] = cost + g1[node][i].second;
                q.push(make_pair(-dist1[g1[node][i].first], g1[node][i].first));
            }
        }
    }
}
 
int main() {
	int x,y,z;
    while(cin>>n>>m && n!=0 && m!=0){
    	cin>>S>>D;
    	for(int i=1;i<=m;i++){
    		cin>>x>>y>>z;
    		g[x].push_back(make_pair(y,z));
    		g1[y].push_back(make_pair(x,z));
		}
		dijkstra(S);
		dijkstra1(D);
		int costf=dist[D];
		for(int i=0;i<n;i++){
			int nr=g[i].size();
			for(int j=0;j<nr;j++){
				if(dist[i]+g[i][j].second+dist1[g[i][j].first]==costf)
				g[i][j].second=oo;
			}
		}
		dijkstra(S);
		if(dist[D]==oo)
		cout<<"-1\n";
		else
		cout<<dist[D]<<"\n";
		memset(g,0,sizeof(g));
		memset(g1,0,sizeof(g1));
	}
	return 0;
}
