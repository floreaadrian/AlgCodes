#include<iostream>
using namespace std;
int main()
{
	int n,s,s1=0,i,a,ma=0;
	cin>>n>>s;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		if(a>ma)ma=a;
		s1+=a;
	}
	if((s1-ma)<=s)cout<<"YES";
	else cout<<"NO";
	return 0;
}
