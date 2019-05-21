#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,n,i;
	cin>>n;
	while(n++){
	a=n%10;
	b=(n/10)%10;
	c=(n/100)%10;
	d=n/1000;
	if(a!=b && a!=d && a!=c && b!=c && b!=d && c!=d){
		cout<<n;
		break;
	}}
	return 0;
}
