#include<iostream>
using namespace std;
int main()
{
	int a,i,j,k=0,l;
	static int p;
	cin>>p;
	cin>>l;
	for(i=9;i>=1;i--)
	{
		a=p;
		while(a>0)
		{
			if(a%10==i)
			{
			j=j+j*10;k++;}
			a=a/10;
		}
		if(k==l)
		break;
	}cout<<l;
	return 0;
}
