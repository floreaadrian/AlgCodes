#include <bits/stdc++.h>
using namespace std;

#define point pair<int,int>
#define x first
#define y second

char g[1030][1030];
int n, m;
bool vi[1030][1030];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs( point u ) {
    vi[u.x][u.y] = 1;
    for( int i = 0; i < 4; i++ ) {
        point v = point( u.x + dx[i], u.y + dy[i] );
        if( 0 <= v.x && v.x < n && 0 <= v.y && v.y < m )
            if( !vi[v.x][v.y] )
                dfs( v );
    }
}

int main() {
    scanf( "%d%d", &n, &m );
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < m; j++ ) {
            scanf( " %c", &g[i][j] );
            if( g[i][j] == 'o' )
                vi[i][j] = 1;
        }

    int cnt = 0;
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < m; j++ )
            if( !vi[i][j] ) {
                dfs( point( i, j ) );
                cnt++;
            }

    printf( "%d\n", cnt );
    return 0;
}
