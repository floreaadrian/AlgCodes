#include<iostream>
#include<math.h>
using namespace std;
int cifre(int n)
{
	while(n>0)
	{
		if(abs(n%10)==8) return 1;
		else n=abs(n/10);
	}return 0;
}
int main()
{
	int n,s=1,l=0;
	cin>>n;
	if(cifre(n)){
	n++;l=1;}
	while(s)
	{
		if(cifre(n))
		{
		cout<<l;			
		s=0;
		}else n++;l++;
	}
	
	return 0;
}
