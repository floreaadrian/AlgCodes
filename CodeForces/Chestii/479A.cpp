#include<iostream>
using namespace std;
int max(int x,int y)
{
	if(x>y)
	return x;
	return y;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<max(a+b+c,max(max(a+b*c,a*(b+c)),max(a*b*c,(a+b)*c)));
}
