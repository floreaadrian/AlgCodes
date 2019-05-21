#include<iostream>
using namespace std;
int main()
{
	int n,pare,i,p;
	pare=0;
	cin>>n;
	for(i=2;i<=n;i++)
	{
		if(i%2==0)
		{
			cout<<i<<endl<<i*i;
		}
	}
}
