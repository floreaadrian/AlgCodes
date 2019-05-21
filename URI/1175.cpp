#include<iostream>
using namespace std;
int main()
{
	int n[20],aux,i;
	for(i=0;i<20;++i)
	cin>>n[i];
	for(i=0;i<10;++i)
	{
		aux=n[19-i];
		n[19-i]=n[i];
		n[i]=aux;
	}
	for(i=0;i<20;++i)
	cout<<"N["<<i<<"] = "<<n[i]<<"\n";
	return 0;
}
