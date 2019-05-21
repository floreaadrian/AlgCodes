#include <bits/stdc++.h>
using namespace std;

#define MAXN 50005
#define non -1
#define vi vector<int>
#define pb push_back

vi AdjList[MAXN], v[MAXN/2];
int pi[MAXN][20], d[MAXN];
queue<int> q;

int LCA( int U, int V ) {
	int D = 0;
	while( U != V ) {
		if( d[U] == d[V] )
			U = pi[U][1], V = pi[V][1], D += 2;

		else if( d[U] > d[V] ) {
			for( int i = 16; i >= 1; i-- )
				if( pi[U][i] != -1 && d[ pi[U][i] ] >= d[V] )
					U = pi[U][i], D += pow( 2, i-1 );

		} else {
			for( int i = 16; i >= 1; i-- )
				if( pi[V][i] != -1 && d[U] <= d[ pi[V][i] ] )
					V = pi[V][i], D += pow( 2, i-1 );
		}
	}
	return D;
}

int main() {
	int n, U, V, pnct = 0;
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ )
		scanf( "%d", &U ), v[U].pb( i );
	for( int i = 1; i <= n; i++ )
		scanf( "%d%d", &U, &V ), AdjList[U].pb(V), AdjList[V].pb(U);

	memset( pi, -1, sizeof pi );
	memset( d, non, sizeof d );
	d[1] = 0;
	q.push( 1 );
	while( !q.empty() ) {
		U = q.front(); q.pop();
		for( int j = 0; j < (int)AdjList[U].size(); j++ ) {
			V = AdjList[U][j];
			if( d[V] == non ) {
				pi[V][1] = U;
				d[V] = d[U] + 1;
				q.push( V );
			}
		}
	}
	for( V = 1; V <= n; V++ )
		for( int i = 2; i <= 16; i++ )
			if( pi[V][i-1] != -1 ) pi[V][i] = pi[ pi[V][i-1] ][i-1];

	for( int i = 1; i <= n/2; i++ )
		pnct += LCA( v[i][0], v[i][1] );
	printf( "%d\n", pnct );
	return 0;
}
