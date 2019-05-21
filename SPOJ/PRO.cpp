#include<iostream>
#include<set>
using namespace std;

set <int> S;
set <int> :: iterator fata,spate;

int main()
{
	long long sum=0;
	int n,i,j,x,m;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>m;
		for(j=0;j<m;j++){
			cin>>x;
			S.insert(x);
		}
		fata=S.begin();
		spate=S.end(); spate--;
		sum+=(*spate-*fata);
		S.erase(fata);
		S.erase(spate);
	}
	cout<<sum;
	return 0;
}
