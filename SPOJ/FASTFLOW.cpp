#include <iostream>
#include <string.h>

using namespace std;

const double EPS = 1e-10;
const int INF = 0x7fffffff;
const int MAXN = 5005, MAXE = 60006;

int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], next[MAXE], to[MAXE];

inline void init(int _src, int _snk, int _n) {
	src = _src, snk = _snk, nNode = _n, nEdge = 0;
	memset(fin, -1, sizeof(fin));
}

inline void add(int u, int v, int c) {
	to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[u], fin[u] = nEdge++;
	to[nEdge] = u, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs() {
	int st, en, i, u, v;
    memset(dist, -1, sizeof(dist));
	dist[src] = st = en = 0;
	Q[en++] = src;
	while(st < en) {
		u = Q[st++];
		for(i=fin[u]; i>=0; i=next[i]) {
			v = to[i];
			if(flow[i] < cap[i] && dist[v]==-1) {
				dist[v] = dist[u]+1;
				Q[en++] = v;
			}
		}
	}
	return dist[snk]!=-1;
}

int dfs(int u, int fl) {
	if(u==snk) return fl;
	for(int &e=pro[u], v, df; e>=0; e=next[e]) {
		v = to[e];
		if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
			df = dfs(v, min(cap[e]-flow[e], fl));
			if(df>0) {
				flow[e] += df;
				flow[e^1] -= df;
				return df;
			}
		}
	}
	return 0;
}

long long dinitz() {
	long long ret = 0;
	int df;
	while(bfs()) {
		for(int i=1; i<=nNode; i++) pro[i] = fin[i];
		while(true) {
			df = dfs(src, INF);
			if(df) ret += (long long)df;
			else break;
		}
	}
	return ret;
}

int main() {
	int n, e, u, v, c, i;
	cin>>n>>e;
	init(1, n, n);
	for(i=0; i<e; i++) {
		cin>>u>>v>>c;
		if(u!=v) add(u, v, c);
	}
	cout<<dinitz();
	return 0;
}
