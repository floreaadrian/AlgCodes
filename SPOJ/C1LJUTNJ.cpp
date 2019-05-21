#include <iostream>
#include <algorithm>
using namespace std;
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
int a[100000];

int main() {
	int n, m, i, ang;
	long long tot = 0, ans = 0;
	cin>>m>>n;
	for(i = 0; i < n; i++) {
		cin>>a[i];
		tot += a[i];
	}
	tot -= m;
	sort(a, a + n);
	for(i = 0; i < n; i++) {
		ang = _min((long long)a[i], tot / (n-i));
		ans += (long long) ang * ang;
		tot -= ang;
	}
	cout<<ans<<"\n";
	return 0;
}
