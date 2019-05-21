#include<iostream>

using namespace std;

int a[100000],n;

void citire()
{
	for(int i=0;i<n;++i)
	cin>>a[i];
}

int Divide(int p,int q)
{
	int st=p,dr=q,x=a[p];
	while(st<dr)
	{
		while(st<dr && a[dr]>=x) dr--;
		a[st]=a[dr];
		while(st<dr && a[st]<=x) st++;
		a[dr]=a[st];
	}
	a[st]=x;
	return st;
}

void QSort(int p,int q)
{
	int m=Divide(p,q);
	if(m-1>p)QSort(p,m-1);
	if(m+1<q)QSort(m+1,q);
}

int main()
{
	int t;
	cin>>t;
	for(int f=1;f<=t;f++)
	{
		cin>>n;
		citire();
		QSort(0,n-1);
		cout<<a[0]+a[1]<<"\n";
	}
	return 0;
}
