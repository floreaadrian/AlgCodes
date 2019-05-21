#include<iostream>
using namespace std;
void citire(int n,int a[])
{
	for(int i=1;i<=n;++i)
	cin>>a[i];
}
int max(int x,int y)
{
	if(x>y)return x;
	return y;
}
int main()
{
	int a[1024],b[1024],c[150][150],n,m,i,j,l=0,k=0,r[256];
	cin>>n>>m;
	citire(n,a);citire(m,b);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
		if(a[i]==b[j])
		{
		c[i][j]=c[i-1][j-1]+1;
		k++;r[l]=a[i];l++;}else c[i][j]=max(c[i-1][j],c[i][j-1]);
	}
	cout<<k<<"\n";
	while(l>0)
	{
		cout<<r[l];l--;
	}
	return 0;
}
