#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float a,rez;
	cin>>a;
	if(a<=2000)
	{
		cout<<"Isento";
	}else
	if(a>2000 && a<=3000)
	{
		a-=2000;
		rez=(double)((a/100)*8);
		cout<<"R$ "<<fixed<<setprecision(2)<<rez;
	}
	else
	if(a>3000 && a<=4500)
	{
		rez=80;
		a-=3000;
		rez+=(double)((a/100)*18);
		cout<<"R$ "<<fixed<<setprecision(2)<<rez;
	}else
	if(a>4500)
	{
		rez=200;
		a-=4500;
		rez+=(double)((a/100)*28);
		cout<<"R$ "<<fixed<<setprecision(2)<<rez;
	}
}
