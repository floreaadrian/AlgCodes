#include <algorithm>
#include <iostream>
using namespace std;
int a,b,n;
int main()
{
	cin>>a>>b>>n;
	while(n>0)
	{
		n-=__gcd(a,n);
		if(n==0)
			{cout<<0<<endl;return 0;}
		n-=__gcd(b,n);
		if(n==0)
			{cout<<1<<endl;return 0;}
	}
}
