#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100009;
const int MOD = 1000000000;

vector < pair< int, pair< int, int > > > G;
int parent[MAX];
long long cnt[MAX], sum[MAX];

int find(int u) {
	if(u != parent[u]) parent[u] = find(parent[u]);
	return parent[u];
}

int main() {
	int n, e, u, v, w, i;
	long long res, cu, cv;
	cin>>n>>e;
	for(i = 0; i < e; i++) {
		cin>>u>>v>>w;
		G.push_back(make_pair(w, make_pair(u, v)));
	}
	sort(G.begin(), G.end());
	for(i = 0; i < e; i++) sum[i] = G[i].first + (i > 0 ? sum[i-1] : 0);
	for(i = 1; i <= n; i++) {
		parent[i] = i;
		cnt[i] = 1;
	}
	for(res = 0, i = G.size() - 1; i >= 0; i--) {
		u = find(G[i].second.first);
		v = find(G[i].second.second);
		if(u != v) {
			cu = cnt[u], cv = cnt[v];
			res += (cu * cv) * sum[i];
			if(res > MOD) res %= MOD;
			parent[u] = parent[v];
			cnt[find(G[i].second.first)] = cu + cv;
			cnt[find(G[i].second.second)] = cu + cv;
		}
	}
	cout<<res<<"\n";
	return 0;
}
