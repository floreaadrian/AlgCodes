#include<iostream>
using namespace std;
int main()
{
	int n, i,p,c=0,j,t=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=3;j++)
		{
			cin>>p;
			t=t+p;
		}
		if(t!=1)
		c++;
		t=0;
	}
	cout<<c;
	return 0;
}
