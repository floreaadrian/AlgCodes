#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector < pair <int,int> > b;
int greedy(int n){
	int count=1;
	int i=0;
	for(int j=1;j<n;j++){
		if(b[j].second>=b[i].first){
			i=j;
			count++;
		}
	}
	return count;
}

int main()
{
	int t,a,c,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a>>c;
			b.push_back(make_pair(c,a));
		}
		sort(b.begin(),b.end());
		int ans=greedy(n);
		cout<<ans<<"\n";
		b.erase(b.begin(),b.begin()+n);
	}
	return 0;
}
