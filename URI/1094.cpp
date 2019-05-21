#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int main()
{
	string si;
	int s=0,c=0,r=0,t=0,i,a,n;
	double nou;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a>>si;
		if(si=="C")c+=a;else
		if(si=="R")r+=a;else
		if(si=="S")s+=a;
	}
	t=c+r+s;
	cout<<"Total: "<<t<<"\n";
	cout<<"Total de coelhos: "<<c<<"\n";
	cout<<"Total de ratos: "<<r<<"\n";
	cout<<"Total de sapos: "<<s<<"\n";
	cout<<"Percentual de coelhos: "<<fixed<<setprecision(2)<<(double)(c*100)/t<<" %"<<"\n";
	cout<<"Percentual de ratos: "<<fixed<<setprecision(2)<<(double)(r*100)/t<<" %"<<"\n";
	cout<<"Percentual de sapos: "<<fixed<<setprecision(2)<<(double)(s*100)/t<<" %";
}
