#include<iostream>
using namespace std;
int main()
{
	int n,i,c=0;
	float v[201],a,b,aux;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
	}
	a=v[1];b=v[n];
	if(a>b)
	{
		a=aux;
		a=b;
		b=aux;
	}
	for(i=1;i<=n;++i)
	{
		if(v[i]>=a && v[i]<=b)c++;
	}
	cout<<c;
}
