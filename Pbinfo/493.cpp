#include<iostream>
using namespace std;
int main()
{
	int n,b,c=0,nrpar=0;
	cin>>n;
	while(cin>>b && b!=0){
		int ok=1;
		int k=b;
		nrpar++;
		if(nrpar%2==0){
		while(k>0 && ok==1){
			if(k%10==n)ok=0;
			k/=10;
		}
		if(ok==0)c++;
		}
	}
	cout<<c;
	return 0;
}
