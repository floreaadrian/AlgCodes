#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	long double r,p=3.14159,a;
	cin>>r;
	a=(double)(p*r*r);
	cout<<"A="<<fixed<<setprecision(4)<<a<<"\n";
}
