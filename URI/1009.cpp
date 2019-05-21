#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
int main()
{
	string nu;
	cin>>nu;
	double a,b,re;
	cin>>a>>b;
	re=a+((b/100)*15);
	cout<<"TOTAL = R$ "<<fixed<<setprecision(2)<<re<<"\n";
}
