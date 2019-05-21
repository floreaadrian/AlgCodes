#include <bits/stdc++.h>

using namespace std;

int n, g[1005][1005], va[1005];

bool dfs( int u, int c ) {
    va[u] = c;
    bool p = true;
    for( int i = 0; i < n && p; i++ ) {
        int v = g[u][i];
        if( !v && u != i ) {
            if( !va[i] )
                p = dfs( i, ( c == 1 ? 2 : 1 ) );
            else if( va[i] == c )
                p = false;
        }
    }
    return p;
}

int main() {
    scanf( "%d", &n );
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < n; j++ )
            scanf( "%d", &g[i][j] );
    memset( va, 0, sizeof va );
    bool p = true;
    for( int i = 0; i < n && p; i++ )
        if( !va[i] )
            p = dfs( i, 1 );
    if( p )
        printf( "Bazinga!\n" );
    else
        printf( "Fail!\n" );

    return 0;
}
