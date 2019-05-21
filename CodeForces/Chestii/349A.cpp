#include<iostream>
using namespace std;
int main()
{
	int n,i,s=0,a,ok=1;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		s+=a;
		if(s/a==0){
		cout<<"NO";ok=0;
		break;}
	}
	if(ok)cout<<"YES";
}
