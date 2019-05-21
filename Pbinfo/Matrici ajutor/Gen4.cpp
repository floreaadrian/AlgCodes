//https://www.pbinfo.ro/?pagina=probleme&id=213
#include<iostream>
using namespace std;
int min(int b,int a)
{
	if(a>b)return a;
	return b;
}
int main()
{
	int a[25][25],m,n,i,j;
	cin>>n;
	m=n;
	for(j=1;j<=n;++j)
	for(i=1;i<=n;++i)
	{
	a[i][j]=(i*j)%10;
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}
