#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,v[15][15],i,j;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		v[1][i]=pow(2,i);
	}
	for(i=2;i<=n;++i)
	for(j=1;i<=n;++i)
	{
		v[i][j]=pow(v[i-1][j],2);
	}
	for(i=1;i<=i;++i)
	{
		for(j=1;j<=n;++j)
		{
			cout<<v[i][j]<<" ";
		}cout<<"\n";
	}
	while(n!=0)
	{
		cin>>n;
		for(i=1;i<=n;++i)
	{
		v[1][i]=pow(2,i);
	}
	for(i=2;i<=n;++i)
	for(j=1;i<=n;++i)
	{
		v[i][j]=pow(v[i-1][j],2);
	}
	for(i=1;i<=i;++i)
	{
		for(j=1;j<=n;++j)
		{
			cout<<v[i][j]<<" ";
		}cout<<"\n";
	}
	}
	return 0;
}
