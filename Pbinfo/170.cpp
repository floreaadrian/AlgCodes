#include<iostream>
using namespace std;
int main()
{
	int mi=9,ma=0,n;
	cin>>n;
	while(n>0)
	{
		if(n%10>ma)ma=n%10;
		if(n%10<mi)mi=n%10;
		n/=10;
	}
	cout<<ma+mi;
}
