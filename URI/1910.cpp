#include <bits/stdc++.h>

using namespace std;

#define valid(a) a >= 1 && a <= 1e5

int main(){
    int O, D, K, cann[100005], aux;
    queue<int> q;
    while( scanf( " %d %d %d", &O, &D, &K ) && O ) {
        while( !q.empty() ) q.pop();
        memset( cann, 0, sizeof cann );
        cann[O] = 1;
        for( int i = 0; i < K; i++ ) {
            scanf( "%d", &aux );
            if( valid( aux ) )
                cann[aux] = -1;
        }
        q.push( O );
        while( !q.empty() ) {
            int aux = q.front(); q.pop();
            if( aux == D ) break;
            int a = aux+1;
            if( valid(a) && cann[a] == 0 ){
                cann[a] = cann[aux] + 1;
                q.push(a);
            }
            a = aux-1;
            if( valid(a) && cann[a] == 0 ){
                cann[a] = cann[aux] + 1;
                q.push(a);
            }
            a = aux*2;
            if( valid(a) && cann[a] == 0 ){
                cann[a] = cann[aux] + 1;
                q.push(a);
            }
            a = aux*3;
            if( valid(a) && cann[a] == 0 ){
                cann[a] = cann[aux] + 1;
                q.push(a);
            }
            a = aux/2;
            if( aux%2 == 0 && valid(a) && cann[a] == 0 ){
                cann[a] = cann[aux] + 1;
                q.push(a);
            }
        }
        if( cann[D] <= 0 ) printf( "-1\n" );
        else printf( "%d\n", cann[D]-1 );
    }
    return 0;
}
