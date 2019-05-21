#include<iostream>
using namespace std;
int fr[20001];
int main()
{
	int n,i,a,m=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		fr[a]++;
		if(a>m)m=a;
	}
	for(i=1;i<=m;++i)
	{
		if(fr[i]>0)
		cout<<i<<" aparece "<<fr[i]<<" vez(es)\n";
	}
}
