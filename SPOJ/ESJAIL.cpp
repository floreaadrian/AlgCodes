#include <queue>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const int MAX = 100001;

bool f[MAX], open[MAX];
int key[MAX];
vector< int > G[MAX];

bool bfs(int u, int dst) {
	int i, sz, v;
	queue< int > Q, P;
	Q.push(u);
	f[u] = 1;
	while(!Q.empty()) {
		while(!Q.empty()) {
			u = Q.front(); Q.pop();
			sz = G[u].size();
			for(i = 0; i < sz; i++) {
				v = G[u][i];
				if(!f[v]) {
					if(!open[v]) {
						f[v] = 1;
						continue;
					}
					if(v == dst) return true;
					if(key[v] && !open[key[v]]) {
						P.push(key[v]);
						open[key[v]] = 1;
					}
					f[v] = 1;
					Q.push(v);
				}
			}
		}
		while(!P.empty()) {
			u = P.front(); P.pop();
			if(open[u] && f[u]) Q.push(u);
		}
	}
	return false;
}

int main() {
	int n, k, m, i, u, v;
	while(cin>>n>>k>>m && n!=-1 && k!=-1 && m!=-1) {
		for(i = 1; i <= n; i++) {
			G[i].clear();
			f[i] = 0;
			key[i] = 0;
			open[i] = 1;
		}
		for(i = 0; i < k; i++) {
			cin>>u>>v;
			key[u] = v;
			open[v] = 0;
		}
		for(i = 0; i < m; i++) {
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(bfs(1, n)) cout<<"Y\n";
		else cout<<"N\n";
	}
	return 0;
}
