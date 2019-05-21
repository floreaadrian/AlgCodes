#include<iostream>
using namespace std;
int main()
{
	int n,k,i,j,a;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>k;
		for(j=1;j<=k;++j)
		{
			cin>>a;
			if(a==1)cout<<"Rolien\n";
		    if(a==2)cout<<"Naej\n";
		    if(a==3)cout<<"Elehcim\n";
		    if(a==4)cout<<"Odranoel\n";
		}
	}
}
