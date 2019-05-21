#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

const int oo = 0x3f3f3f3f;
const int maxn = 1000001;
vector < pair < int,int > > g[maxn],g1[maxn];
int n,dist[maxn],dist1[maxn];

void citire(){
	int m;
	cin>>n>>m;
	while(m--){
		int x,y,z;
		cin>>x>>y>>z;
		g[x].push_back(make_pair(y, z));
		g1[y].push_back(make_pair(x, z));
	}
}

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

void afisare()
{
	int total=0;
	for(int i=1;i<=n;i++)
	total+=dist[i]+dist1[i];
	cout<<total<<"\n";
}

int main()
{
	int ptr;
	cin>>ptr;
	while(ptr--)
	{
	citire();
	dijkstra(1);
	dijkstra1(1);
	afisare();
	memset(g,0,sizeof(g));
	memset(g1,0,sizeof(g1));
	}
}
