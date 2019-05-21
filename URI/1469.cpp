#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <bitset>
#include <vector>

using namespace std;

vector<int> g[505];
int dd[505];
bitset <505> viz;

int dfs( int node, bool m ) {
	int m1 = m ? 101 : dd[node];

	viz[node] = true;
	for( int i=0, j; i<g[node].size(); i++ ) {
		j = g[node][i];
		if( !viz[j] )
			m1 = min( m1, dfs( j, 0 ) );
	}

	return m1;
}

int main() {
	int N, M, I, X, Y, E, m1;
	char inst;
	while( cin >> N >> M >> I ) {
		for( int i=0; i<N; i++ ) {
			g[i].clear();
			cin >> dd[i];
		}
		for( int i=0; i<M; i++ ) {
			cin >> X >> Y;
			g[Y-1].push_back( X-1 );
		}
		while( I-- ) {
			cin >> inst;
			if( inst == 'P' ) {
				cin >> E;
				viz.reset();
				m1 = dfs( E-1, 1 );
				if( m1 == 101 ) printf("*\n");
				else printf("%d\n",m1);

			} else {
				cin >> X >> Y;
				swap( g[X-1], g[Y-1] );
				for( int i=0; i<N; i++ )
					for( int j=0; j<g[i].size(); j++ ) {
						if( g[i][j] == X-1 ) g[i][j] = Y-1;
						else if( g[i][j] == Y-1 ) g[i][j] = X-1;
					}
			}
		}
	}

	return 0;
}
