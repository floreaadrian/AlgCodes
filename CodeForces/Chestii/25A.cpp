#include<iostream>
using namespace std;
int main()
{
	int n,i,last_odd=0,last_even=0,a,ce=0,co=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		if(a%2==0){
		last_even=i;
		ce++;}else
		{
		last_odd=i;co++;}
    }
    if(ce==1)cout<<last_even;else
    cout<<last_odd;
}
