#include<iostream>
using namespace std;
int a[5],t,n;
int main()
{
	cin>>n;
	while(n>0);
	{
	cin>>t;a[t]++;n--;
	}
	cout<<a[4]+a[3]+(a[1]+2*a[2]+3)/4;
}
