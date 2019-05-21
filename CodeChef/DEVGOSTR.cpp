#include<iostream>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

vector < string > res;
vector < vector < string > > _aa;
vector < int > v;
string _t;
int t, a, k, n;
string s;

void rec( int sz, vector < bool > tt ){

	if( !v.empty() && v[sz-1] >= n-3 ){
		vector < int > tmp;
		bool aa[n+1];
		memset( aa, 0, sizeof(aa) );

		for(int i = 0 ; i < sz ; i++) aa[ v[i] ] = 1;

		for(int i = 0 ; i < n ; i++){
			if( !aa[i] ) tmp.push_back( i );
			aa[i] = !aa[i];
		}

		bool check = 1;

		for(int i = 0 ; i < tmp.size()-1 && check ; i++){
			for(int j = i+1 ; j < tmp.size() && check ; j++){
				if( 2 * tmp[j] - tmp[i] < n && aa[ 2 * tmp[j] - tmp[i] ] )
					check = 0;
			}
		}
		if( check ){
			_t.clear();
			memset( aa, 0, sizeof(aa) );
			for(int i = 0 ; i < sz ; i++){
				aa[v[i]] = 1;
			}
			for(int i = 0 ; i < n ; i++){
				if( aa[i] ) _t += 'a';
				else _t += 'b';
			}
			res.push_back( _t );
		}
	}

	for(int i = sz - 2 ; i >= 0 ; i--)
		if( 2 * v[sz-1] - v[i] < n ) tt[ 2 * v[sz-1] - v[i] ] = 1;

	for(int i = 1 ; i <= 3 ; i++){
		if( v[sz-1] + i < n && !tt[ v[sz-1] + i ] ){
			v.push_back( v[sz-1] + i );
			rec( sz+1, tt );
			v.pop_back();
		}
	}
}

int _cnt(){
	int cnt = 0;
	for(int i = 0 ; i < res.size() ; i++){
		int dis = 0;
		for(int j = 0 ; j < n ; j++)
			if( s[j] != res[i][j] ) dis++;
		if( dis <= k ) cnt++;
	}
	return cnt;
}

void gene( int sz ){
	if( sz == n ){
		vector < int > tmp;
		bool aa[n+1];

		memset( aa, 0, sizeof(aa) );
		for(int i = 0 ; i < n ; i++)
			if( v[i] == 0 ) tmp.push_back(i), aa[i] = 1;

		if( !tmp.empty() )
		for(int i = 0 ; i < tmp.size()-1 ; i++){
			for(int j = i+1 ; j < tmp.size() ; j++){
				if( 2 * tmp[j] - tmp[i] < n && aa[ 2 * tmp[j] - tmp[i] ] )
					return;
			}
		}

		tmp.clear();
		memset( aa, 0, sizeof(aa) );
		for(int i = 0 ; i < sz ; i++)
			if( v[i] == 1 ) tmp.push_back(i), aa[i] = 1;
		if( !tmp.empty() )
		for(int i = 0 ; i < tmp.size()-1 ; i++){
			for(int j = i+1 ; j < tmp.size() ; j++){
				if( 2 * tmp[j] - tmp[i] < n && aa[ 2 * tmp[j] - tmp[i] ] )
					return;
			}
		}

		tmp.clear();
		memset( aa, 0, sizeof(aa) );
		for(int i = 0 ; i < sz ; i++)
			if( v[i] == 2 ) tmp.push_back(i), aa[i] = 1;

		if( !tmp.empty() )
		for(int i = 0 ; i < tmp.size()-1 ; i++){
			for(int j = i+1 ; j < tmp.size() ; j++){
				if( 2 * tmp[j] - tmp[i] < n && aa[ 2 * tmp[j] - tmp[i] ] )
					return;
			}
		}

		string _t;
		for(int i = 0 ; i < sz ; i++ )
			_t += char( v[i] + 'a' );
//		cout << _t << endl;
		res.push_back( _t );
		return;
	}

	for(int i = 0 ; i <= 2 ; i++ ){
		v.push_back( i );
		gene( sz+1 );
		v.pop_back();
	}

}

int main()
{
	_aa.resize(13);
	for(n = 1 ; n <= 12 ; n++){
		v.clear();
		res.clear();
		gene( 0 );
		while( !res.empty() ){
			_aa[n].push_back( res.back() );
			res.pop_back();
		}
	}

	cin >> t;
	while( t-- ){
		cin >> a >> k >> s;
		n = s.size();
		if( a == 1 ) {
			if( n < 3 ) cout << "1\n";
			else cout << "0\n";
		}
		if( a == 2 ){
			if( n >= 3 ){
				res.clear();
				vector < bool > t_t(n+1);
				for(int i = 0 ; i <= 2 ; i++){
					v.clear();
					v.push_back(i);
					rec( 1, t_t );
				}
				cout << _cnt() << endl;
			}
			else{
				res.clear();
				if( n == 2 ){
					res.push_back( "aa" );
					res.push_back( "ab" );
					res.push_back( "ba" );
					res.push_back( "bb" );
				}
				else{
					res.push_back( "a" );
					res.push_back( "b" );
				}
				cout << _cnt() << endl;
			}
		}
		if( a == 3 ){
			if( n > 12 ) return 0;
			int cnt = 0;
			for(int i = 0 ; i < _aa[n].size() ; i++){
				int dis = 0;
				for(int j = 0 ; j < n ; j++)
					if( s[j] != res[i][j] ) dis++;
				if( dis <= k ) cnt++;
			}
			cout << cnt << endl;
		}
	}
}
