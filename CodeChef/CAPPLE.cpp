#include<iostream>
using namespace std;
int min(int v[],int n)
{
	int k,min=INT_MAX;
	for(k=1;k<=n;++k)
	{
		if(min > v[k])
        {
               min = v[k];
        }
	}
	return min;
}
int verificare(int v[],int n,int f)
{
	int i;
	for(i=1;i<=n;++i)
	{
		if(v[i]!=f)
		return 0;
	}
	return 1;
}
int main()
{
	int n,t,f,i,j,l=0,v[1000],m;
	cin>>t;
	for(i=1;i<=t;++i)
	{
		cin>>n;
		for(j=1;j<=n;++j)
		{
			cin>>v[j];
		}
		f=min(v,n);
		for(j=1;j<=n;++j)
		{
			if(v[i]!=f)
			{
			m=v[i]-f;
			v[i]=v[i]+m;
			l++;
			}
			if(verificare)
			cout<<l;
		}
	}
	return 0;
}
