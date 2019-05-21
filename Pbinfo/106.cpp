#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,a,b,c;
	cin>>n;
	a=n%10;
	b=n/100;
	c=(n/10)%10;
	int max1=max(a,max(b,c));
	int min1=min(a,min(b,c));
	if(a!=max1 && a!=min1)
	cout<<a;else
	if(b!=max1 && b!=min1)
	cout<<b;else
	cout<<c;
}
