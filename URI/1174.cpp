#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float a[100];
	int i;
	for(i=0;i<100;++i)
	cin>>a[i];
	for(i=0;i<100;++i)
	{
		if(a[i]<=10)
		cout<<"A["<<i<<"] = "<<fixed<<setprecision(1)<<a[i]<<"\n";
	}
	return 0;
}
