#include<iostream>
using namespace std;
int main()
{
	int n,x=4,y,ok=1;
	cin>>n;
	if(n%4==0)
	y=n-x;
	else {
		x=9;
		y=n-x;
	}
	cout<<x<<" "<<y;
	return 0;
}
