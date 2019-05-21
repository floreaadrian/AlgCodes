#include<iostream>
using namespace std;
int main()
{
	int n,ok=0,a[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
	cin>>n;
	for(int i=1;i<=14;++i)
	{
		if(n%a[i]==0){
		ok=1;break;}
	}if(ok)cout<<"YES";else cout<<"NO";
	return 0;
}
