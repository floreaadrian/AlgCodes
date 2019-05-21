#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9

int n, visited[11000], c[105], l[105], ec[105], el[105];
map<int,int> cap[11000];

int caminho( int u, int t, int f ) {
    if( u == t ) return f;
    visited[u] = 1;

    for( map<int,int>::iterator it = cap[u].begin(); it != cap[u].end(); it++ ) {
        int v = it->first;
        if( !visited[v] && it->second > 0 ) {
			int df = caminho( v, t, min( f, cap[u][v] ) );
			if( df > 0 ) {
				it->second -= df;
				cap[v][u] += df;
				return df;
			}
		}
    }
    return 0;
}

int fordfulkerson() {
	for( int flow = 0; ; ) {
		memset( visited, 0, sizeof visited );
		int df = caminho( 0, 1, INF );
		if( df == 0 ) return flow;
		flow += df;
	}
}

int main() {
    char mij;

    while( scanf( "%d", &n ) != EOF ) {
        for( int i = 0; i < 11000; i++ ) cap[i].clear();
        memset( el, 0, sizeof el );
		memset( ec, 0, sizeof ec );

        int no = 2;
        for( int i = 0; i < n; i++ ) l[i] = no++, c[i] = no++;

        for( int i = 0; i < n; i++ )
            for( int j = 0; j < n; j++ ) {
                scanf( " %c", &mij );
                if( mij == 'X' ) {
                    if( el[i] ) l[i] = no++;
                    if( ec[j] ) c[j] = no++;
                } else {
                    el[i] = 1;
                    ec[j] = 1;
                    cap[0][ l[i] ] = 1;
                    cap[ l[i] ][ c[j] ] = 1;
                    cap[ c[j] ][1] = 1;
                }
            }

        printf( "%d\n", fordfulkerson() );
    }

    return 0;
}
