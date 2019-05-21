#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int d[10001],n;
vector < pair <int,int> > a[10001];
int main(){
	char c;
	c=' ';
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			a[x].push_back(make_pair(z,y));
			a[y].push_back(make_pair(z,x));
		}
	while(c!='DONE'){
		
		cin>>c;
		cout<<c;
	}
	}
	return 0;
}
