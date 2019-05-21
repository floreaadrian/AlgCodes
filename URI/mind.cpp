#include<iostream>
using namespace std;
int main()
{
	int x,y,n,i,a,v[1001];
	cin>>x>>y;
	cin>>n;
	x=x-2;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		if(x%a==0 || y%a==0)v[i]=1;
	}
	for(i=1;i<=n;++i)
	if(v[i]==1)
	cout<<"YES\n";else cout<<"NO\n";
	return 0;
}
