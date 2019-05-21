#include<iostream>
using namespace std;
int main()
{
	int n,a,i,b=1;
	cin>>n;
	for(i=2;i<=n/2;i++)
	if(n%i==0)b=b+i;
	if(b==n)cout<<"Perfect";else cout<<"Nu e perfect";
	return 0;
}
