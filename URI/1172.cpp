#include<iostream>
using namespace std;
int main()
{
	int x[10],i,j,n;
	for(i=0;i<10;++i)
	{
		cin>>x[i];
		if(x[i]<=0)
		x[i]=1;
	}
	for(i=0;i<10;++i)
	cout<<"X["<<i<<"] = "<<x[i]<<"\n";
	return 0;
}
