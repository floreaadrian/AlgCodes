#include<iostream>

using namespace std;

int rev(int a)
{
	int c=0;
	while(a)
	{
		c=c*10+a%10;
		a/=10;
	}
	return c;
}

int main()
{
	int a,b,s,l,n;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		s=rev(a)+rev(b);
		cout<<rev(s)<<"\n";
	}
	return 0;
}
