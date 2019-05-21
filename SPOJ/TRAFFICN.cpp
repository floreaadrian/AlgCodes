#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
 
using namespace std;

const int maxn = 100001;
const int oo = 0x3f3f3f3f;
 
int n, m, dist[maxn],s,t;
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
int main()
{
	int nrdece,k;
	cin>>nrdece;
	while(nrdece--){
		int min1;
		cin>>n>>m>>k>>s>>t;
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			g[x].push_back(make_pair(y,z));
		}
		dijkstra(s);
		min1=dist[t];
		int as=min1;
		for(int i=1;i<=k;i++){
			int x,y,z;
			cin>>x>>y>>z;
			g[x].push_back(make_pair(y,z));
			g[y].push_back(make_pair(x,z));
			dijkstra(s);
			if(dist[t]<min1)
			min1=dist[t];
			int j=g[x].size();
			g[x][j].second=oo;
			j=g[y].size();
			g[y][j].second=oo;
		}if(min1==as)
		cout<<"-1\n";else
		cout<<min1<<"\n";
		
	}
	return 0;
}
