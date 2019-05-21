#include<iostream>

using namespace std;

int main()
{
	long long a,b,n;
	cin>>n;
	while(n--)
	{
		cin>>a;
		long long p=1;
		for(int i=1;i<=a;i++)
		p=p*i;
		cout<<p<<"\n";
	}
	return 0;
}
