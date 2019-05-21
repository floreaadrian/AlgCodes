#include<iostream>
using namespace std;
int main()
{
	float a;
	cin>>a;
	if(a<0 || a>100)
	{
		cout<<"Fora de intervalo";
	}else;
	if(a>=0 && a<=25)
	cout<<" Intervalo [0,25] \n";
	else if(a>25 && a<=50)
	cout<<" Intervalo (25,50] \n";
	else if(a>50 && a<=75)
	cout<<" Intervalo (50,75] \n";
	else if(a>75 && a<=100)
	cout<<" Intervalo (75,100] \n";
}
