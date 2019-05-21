#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAX = 111;
int M, N, indeg[MAX];
set <int> g[MAX], nextNode;
vector< int > order;

void topology() {
	int u, v;
	set < int >::iterator it;
	while(!nextNode.empty()) {
		u = *nextNode.begin();
		nextNode.erase(nextNode.begin());
		order.push_back(u);
		for(it=g[u].begin(); it!=g[u].end(); it++) {
			v = *it;
			indeg[v]--;
			if(!indeg[v]) nextNode.insert(v);
		}
	}
}

int main() {
	int i, j, k, u, v;
	cin>>N>>M;
	for(i=0; i<M; i++) {
		cin>>u>>k;
		for(j=0; j<k; j++) {
			cin>>v;
			g[v].insert(u);
		}
		indeg[u] += k;
	}
	for(i=1; i<=N; i++)
		if(!indeg[i])
			nextNode.insert(i);
	topology();
	cout<<order[0]<<" ";
	for(i=1; i<N; i++)	cout<<order[i]<<" ";
	cout<<"\n";
	return 0;
}
