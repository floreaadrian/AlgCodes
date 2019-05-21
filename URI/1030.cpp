#include<iostream>


using namespace std;

int v[10000],n,k,l,m;

void mod(int n,int k)
{
	int i=0,c=0;
	bool ok=true;
	while(ok)
	{
		if(v[i+k]==0){
		v[i+k]=1;
		i+=k;
		m=i;
		c++;
		}
		else while(v[i]==1)
		{
			i++;
		}
		if(i>n)
		i=m;
		if(c==n-1)
		break;
	}
}

int main()
{
	cin>>l;
	for(int f=1;f<=l;f++)
	{
		cin>>n>>k;
		mod(n,k);
		cout<<"Case "<<f<<": "<<m<<"\n";
	}
}
