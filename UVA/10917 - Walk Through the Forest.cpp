#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 200000000
const int oo = 0x3f3f3f3f;
int N, M;

vector < pair <int,int> > g[1001];
int dist[1001];
int paths[1001];

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

int countPaths(int to){
    if( paths[to] != -1) return paths[to];
    int ways = 0;
    int from;
    for( int i = 0; i < (int) g[to].size(); i++ ){
        from = g[to][i].first;
        if( dist[from] > dist[to] ) ways += countPaths(from);
    }
    return paths[to] = ways;
}

int main(){

    int from, to, wt;
    while(cin>>N && N){
    	cin>>M;
        for( int i = 1; i <= M; i++ ){
        	int x,y,z;
           	cin>>x>>y>>z;
            g[x].push_back(make_pair(y, z));
            g[y].push_back(make_pair(x, z));
        }
        dijkstra(2);
        memset(paths, -1, sizeof(paths));
        paths[1] = 1;
        cout<<countPaths(2)<<"\n";
        memset(g,0,sizeof(g));
    }
	return 0;
}

