#include<iostream>
using namespace std;
int main()
{
	int i,a,b,c;
	cin>>a;
	if(a%2==0)
	{
	cout<<a<<"\n";
	cout<<1<<" ";
	for(b=2;b<a;b+=2)
	{
		cout<<a+1-b<<" ";
	}
	cout<<a<<" ";
	for(b=2;b<a;b+=2)
	cout<<b<<" ";
	}else
	{
	cout<<a-1<<"\n";
	
	for(b=2;b<a-1;b+=2)
	{
		cout<<a+1-b<<" ";
	}
	cout<<a<<" ";
	for(b=2;b<a-1;b+=2)
	cout<<b<<" ";
    }
	
	return 0;
}
