#include<iostream>
using namespace std;
int max(int m, int b)
{
	if(b>m)
	return b;else
	return m;
}
int main()
{
	int n,p,k,l,m=0,a[1001],i,j,t,b;
	cin>>t;
	for(j=1;j<=t;++j)
	{
		cin>>n>>k;
		for(i=1;i<=n;++i)
		{
			cin>>a[i];
			b=a[i];
			m=max(m,b);
		}
		l=m+k;
		cout<<l;
	}
}
