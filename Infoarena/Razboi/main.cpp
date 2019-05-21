#include <fstream>
#include <iostream>
#include <vector>
#define oo 0x3f3f3f3f

using namespace std;

int t, n, up[16005], down[16005];
vector <pair<int, int> > g[16005];

inline void dfs(int node, int father) {
	for(auto it:g[node]) {
		if(it.first == father)
			continue;
		dfs(it.first, node);
		down[node] = max(down[node], down[it.first] + it.second);
	}
}

inline void getmax(int &a, int &b, int c) {
	if(c > a) {
		b = a;
		a = c;
		return;
	}
	if(c > b)
		b = c;
}

inline void dfsup(int node, int father) {
	int a = up[node], b = 0;
	for(auto it:g[node]) {
		if(it.first == father)
			continue;
		getmax(a, b, down[it.first] + it.second);
	}
	for(auto it:g[node]) {
		if(it.first == father)
			continue;
		if(a == down[it.first] + it.second)
			up[it.first] = b;
		else
			up[it.first] = a;
		up[it.first] += it.second;
		dfsup(it.first, node);
	}
}

int main() {
	FILE *fin,*fout;
	fin = fopen("razboi.in","r");
	fout = fopen("razboi.out","w");
	fscanf(fin,"%d",&t);
	for(int tt = 1 ; tt <= t ; ++ tt) {
		fprintf(fout,"Testul nr #%d\n",tt);
		fscanf(fin,"%d",&n);
		for(int i = 1 ; i < n ; ++ i) {
			int x, y, z;
			fscanf(fin,"%d%d%d",&x,&y,&z);
			g[x].push_back(make_pair(y, z));
			g[y].push_back(make_pair(x, z));
		}
		dfs(1, 0);
		dfsup(1, 0);
		int ans = oo;
		for(int i = 1 ; i <= n ; ++ i)
			if(ans > max(down[i], up[i]))
				ans = max(down[i], up[i]);
		for(int i = 1 ; i <= n ; ++ i)
			if(ans == max(down[i], up[i]))
				fprintf(fout,"%d\n",i);
		for(int i = 1 ; i <= n ; ++ i) {
			down[i] = up[i] = 0;
			vector <pair<int, int> > ().swap(g[i]);
		}
	}
}
