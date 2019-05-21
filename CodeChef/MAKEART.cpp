#include <iostream>

using namespace std;

int main() {
	int i,j,k,t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		int ar[n];
		bool ok=false;
		for(i = 0; i < n; i++) {
			cin>>ar[i];
			if(i > 1) {
				if(ar[i] == ar[i-1] && ar[i] == ar[i-2]) {
					ok=true;
				}
			}
		}
		if(ok)
            cout<<"Yes\n";
            else cout<<"No\n";
    }
	return 0;
}
