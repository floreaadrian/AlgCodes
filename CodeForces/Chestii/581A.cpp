#include<iostream>

using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b;
	if(a>b)
	{
		cout<<b<<" ";
		if(a-b==1)
		cout<<0;
		else
		if(a-b==2)
		cout<<1;
		else cout<<(a-b)/2;
	}else
	{
		cout<<a<<" ";
		if(b-a==1)
		cout<<0;
		else
		if(b-a==2)
		cout<<1;
		else cout<<(b-a)/2;
	}
	return 0;
}
