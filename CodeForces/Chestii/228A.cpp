#include<iostream>
using namespace std;
int main()
{
	int n,i,k,a[4],c=0;
	for(i=1;i<=4;++i)
	{
		cin>>a[i];
	for(int k=1;k<i;++k)
	if(a[i]==a[k])
	{
	c++;break;}
	}
	cout<<c;
}
