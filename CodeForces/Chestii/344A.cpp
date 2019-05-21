#include<iostream>
using namespace std;
int main()
{
	int n,i,a,l=0,b;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		if(a!=b)l++;
		b=a;
	}
	cout<<l;
}
