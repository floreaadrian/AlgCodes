#include<iostream>

using namespace std;

int main()
{
	int a1,a,b,i,ma,co;
	cin>>a;
	ma=0;
	co=1;
	cin>>a1;
	for(i=1;i<a;i++)
	{
		cin>>b;
		if(a1<=b)
			co++;
		else
		{
			if(co>ma)
				ma=co;
			co=1;
		}
		a1=b;
	}
	cout<<ma;
	return 0;
}
