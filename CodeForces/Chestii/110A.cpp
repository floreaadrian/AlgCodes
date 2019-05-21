#include<iostream>
using namespace std;
int main()
{
	long long n,ok=0,ok1=0,ok2=0,i;
	cin>>n;
	while(n>0)
	{
		if(n%10==4 || n%10==7)
		{
			ok=1;ok2++;
		}
		n=n/10;
	}
	if(ok==1 && (ok2==4 || ok2==7))
	cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
