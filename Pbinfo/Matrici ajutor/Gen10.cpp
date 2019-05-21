//https://www.pbinfo.ro/?pagina=probleme&id=219
#include<iostream>
using namespace std;
int main()
{
	int a[25][25],m,n,i,j,c;
	cin>>n>>m;
	c=n*m;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
		a[i][j]=c;
		c--;
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}
