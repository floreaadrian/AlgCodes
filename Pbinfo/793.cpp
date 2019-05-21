#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c,a1,b1,c1;
	cin>>a>>b>>c;
	a1=a*b+c;
	b1=a*c+b;
	c1=b*c+a;
	int r=max(a1,max(b1,c1));
	cout<<r;
}
