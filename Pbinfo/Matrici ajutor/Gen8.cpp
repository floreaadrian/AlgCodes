//https://www.pbinfo.ro/?pagina=probleme&id=217
#include<iostream>
using namespace std;
int main()
{
	int a[25][25],m,n,i,j;
	cin>>n;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	{
		if(i%2==0)
		a[i][j]=j;else
		a[i][j]=i;
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}
