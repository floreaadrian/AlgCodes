#include<iostream>
using namespace std;
int main()
{
	int t,n,a,b,an;
	cin>>t;
	for(int f=1;f<=t;f++)
	{
		an=0;
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>a>>b;
			an^=i;
		}
		cout<<an<<"\n";
	}
	return 0;
}
