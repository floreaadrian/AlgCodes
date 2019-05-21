#include<iostream>
#include<cmath>
using namespace std;

long long ans[100005];

long long fun(int a)
{
	long long k=0,i,z;
	for(i=1;i*i<=a;i++)
	{
		if(a%i==0)
		{
			if(i%2==1)
			{

				k=k+i;
				z=a/i;
				if(z!=i)
				if(z%2==1)
					k=k+z;
			}
			else if(i%2==0)
			{
				z=a/i;
				if(z%2==1)
					k=k+z;
			}
		}
	}
		return k;
}

int main()
{
	long long t,i,l,r;
	cin>>t;
	for(i=1;i<=100000;i++)
	{
		ans[i]=fun(i);
	}
	while(t--)
	{
		long long s=0;
		cin>>l>>r;
		for(i=l;i<=r;i++)
		{
			s=s+ans[i];
		}
		cout<<s<<"\n";
	}
	return 0;
}
