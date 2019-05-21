#include<iostream>
#include<math.h>
using namespace std;
int c=0;
int nrcif(int k){
	while(k>0){
		c++;
		k/=10;
	}
	return c;
}
int main()
{
	int n,x,a=0,b1,p10=1;
	cin>>n;
	int nrcf=nrcif(n),b=nrcf/2;	
	while(b--){
		a=a+(n%10)*p10;
		p10*=10;
		n/=10;
	}
	if(nrcf%2==0)
	b1=n;
	else b1=n/10;
	x=abs(b1-a);
	cout<<x;
	return 0;
}
