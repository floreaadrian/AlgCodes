//https://www.pbinfo.ro/?pagina=probleme&id=313
#include<iostream>
using namespace std;
int main()
{
	int a[21][21],n,i,j,s1=0,s2=0;
	cin>>n;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	cin>>a[i][j];
	for(i=1;i<=n;++i)
	s1+=a[i][i];
	for(i=1;i<=n;++i)
	s2+=a[i][n+1-i];
	if(s1>s2)cout<<s1-s2;else
	cout<<s2-s1;
}
