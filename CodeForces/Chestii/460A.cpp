#include<iostream>
using namespace std;
int nm(int n,int m)
{
	int x=0;
	x=n+n/m;
	if(x%m==0)
	x++;
	return x;
}
int main()
{
	int n,m,x=0;
	cin>>n>>m;
	cout<<nm(n,m);
	return 0;
}
