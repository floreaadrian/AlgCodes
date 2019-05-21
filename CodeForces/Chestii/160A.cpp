#include<iostream>
#include<algorithm>
using namespace std;
bool  descr(int a, int b)
{
return a>b;
}
int main()
{
	int v[100],i,s=0,s1=0,n,k=0,l=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		s=s+v[i];
	}
	sort(v+1,v+n+1,descr);
	for(i=1;i<=n;++i)
	{
		s1=s1+v[i];
		if(s1>s-s1)
		{l=i;break;
		}
	}
	cout<<l;
}
