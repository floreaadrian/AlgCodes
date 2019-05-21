#include<iostream>

using namespace std;

int di,v[51];

int cmmdc(int a, int b)
{
	if(b==0)
		return a;
	else
	{
		return cmmdc(b,a%b);
	}
}

void refresh(int n)
{
	for(int i=1;i<=n;++i)
	v[i]/=di;
}

int main()
{
	int t,n,i;
	cin>>t;
	for(int f=1;f<=t;++f)
	{
		cin>>n;
		for(i=1;i<=n;++i)
		cin>>v[i];
		di = v[1];
		for(i=2;i<n;++i)
		{
			di=cmmdc(di,v[i]);
		}
		refresh(n);
		for(i=1;i<=n;++i)
		cout<<v[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
