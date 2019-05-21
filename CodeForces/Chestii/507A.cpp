#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int s=0,n,v[101],k,i,j=0;
	cin>>n>>k;
	for(i=1;i<=n;++i)
	{cin>>v[i];
	}
	sort(v + 1, v + n + 1);
	for(i=1;i<=n;++i)
	{
		s=s+v[i];
		if(s<=k){j++;
	}
	}
	cout<<j<<"\n";
	s=0;
	for(i=1;i<=n;++i)
	{
		s=s+v[i];
		if(s<=k)cout<<v[i]<<" ";
	}
	return 0;
}
