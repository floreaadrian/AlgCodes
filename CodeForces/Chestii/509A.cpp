#include<iostream>
using namespace std;
int a[11][11];
int main()
{
	int i,j,n,s=0;
	cin>>n;
	for(j=1;j<=n;++j)
	a[1][j]=1;
	for(i=2;i<=n;++i)
	for(j=1;j<=n;++j)
	a[i][j]=a[i-1][j]+a[i][j-1];
	cout<<a[n][n];
}
