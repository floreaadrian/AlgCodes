#include <bits/stdc++.h>

using namespace std;

#define point pair<int,int>

int dp[10][10];
queue<point> q;

int main() {
	string pa, pb;
	point a, b, A, B;

	while( cin >> pa >> pb ) {
		while( !q.empty() ) q.pop();
		a = point( (int)( pa[0] - 'a' ), (int)( 8 - ( pa[1] - '0' ) ) );
		b = point( (int)( pb[0] - 'a' ), (int)( 8 - ( pb[1] - '0' ) ) );

		q.push( a );
		memset( dp, -1 , sizeof(dp));
		dp[a.first][a.second] = 0;
		while( !q.empty() ) {
			A = q.front(), q.pop();
			if( A == b ) break;
			if( A.first - 1 >= 0 ) {
				if( A.second - 2 >= 0 ) {
					B = point( A.first - 1, A.second - 2 );
					if( dp[B.first][B.second] == -1 ) {
						dp[B.first][B.second] = dp[A.first][A.second] + 1;
						q.push( B );
					}
				}
				if( A.second + 2 < 8 ) {
					B = point( A.first - 1, A.second + 2 );
					if( dp[B.first][B.second] == -1 ) {
						dp[B.first][B.second] = dp[A.first][A.second] + 1;
						q.push( B );
					}
				}
			}
			if( A.first + 1 < 8 ) {
				if( A.second - 2 >= 0 ) {
					B = point( A.first + 1, A.second - 2 );
					if( dp[B.first][B.second] == -1 )
						dp[B.first][B.second] = dp[A.first][A.second] + 1, q.push( B );
				}
				if( A.second + 2 < 8 ) {
					B = point( A.first + 1, A.second + 2 );
					if( dp[B.first][B.second] == -1 )
						dp[B.first][B.second] = dp[A.first][A.second] + 1, q.push( B );
				}
			}
			if( A.first - 2 >= 0 ) {
				if( A.second - 1 >= 0 ) {
					B = point( A.first - 2, A.second - 1 );
					if( dp[B.first][B.second] == -1 )
						dp[B.first][B.second] = dp[A.first][A.second] + 1, q.push( B );
				}
				if( A.second + 1 < 8 ) {
					B = point( A.first - 2, A.second + 1 );
					if( dp[B.first][B.second] == -1 )
						dp[B.first][B.second] = dp[A.first][A.second] + 1, q.push( B );
				}
			}
			if( A.first + 2 < 8 ) {
				if( A.second - 1 >= 0 ) {
					B = point( A.first + 2, A.second - 1 );
					if( dp[B.first][B.second] == -1 )
						dp[B.first][B.second] = dp[A.first][A.second] + 1, q.push( B );
				}
				if( A.second + 1 < 8 ) {
					B = point( A.first + 2, A.second + 1 );
					if( dp[B.first][B.second] == -1 )
						dp[B.first][B.second] = dp[A.first][A.second] + 1, q.push( B );
				}
			}
		}
		cout << "To get from " << pa << " to " << pb << " takes " << dp[b.first][b.second] << " knight moves.\n";
	}

	return 0;
}
