//https://www.pbinfo.ro/?pagina=probleme&id=208
#include<iostream>
using namespace std;
int main()
{
	int a[21][21],n,m,i,j,k,s=1;
	bool ok;
	cin>>n>>m;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
		a[i][j]=s*s;
		s+=2;
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}
