#include<iostream>
using namespace std;
int main()
{
	int n[1000],i,t;
	cin>>t;
	for(i=0;i<1000;++i)
	{
		for(int j=0;j<t;++j)
		{
			n[i]=j;
			i++;
		}i--;
	cout<<"N["<<i<<"] = "<<n[i]<<"\n";
	}
}
