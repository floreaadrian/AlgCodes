#include<iostream>
using namespace std;

int main()
{
	int n,a,b,i,c=0,r=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a>>b;
		c=c-a+b;if(c>r)r=c;
	}
	cout<<r<<" ";
	return 0;
}
