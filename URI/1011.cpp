#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
int main()
{
	double a,re;
	cin>>a;
	re=(4/3.0)*3.14159*(double)(a*a*a);
	cout<<"VOLUME = "<<fixed<<setprecision(3)<<re<<"\n";
}
