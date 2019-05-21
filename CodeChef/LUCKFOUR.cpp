#include<iostream>
using namespace std;

int ca(int a)
{
	int c=0;
	while(a)
	{
		if(a%10==4)c++;
		a/=10;
	}
	return c;
}

int main()
{
	int t,b,n;
	cin>>t;
	for(int f=1;f<=t;f++)
	{
		cin>>n;
		b=ca(n);
		cout<<b<<"\n";
	}
	return 0;
}
