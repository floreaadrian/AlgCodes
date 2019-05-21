#include<iostream>
using namespace std;
int main()
{
	float a,b;
	cin>>a>>b;
	if(a==0 && b==0)
	cout<<"Origem";
	else
	if(a==0)
	cout<<"Eixo X";else
	if(b==0)
	cout<<"Eixo Y";else
	if(a<0)
	{
		if(b<0)cout<<"Q3";else
		cout<<"Q2";
	}
	else
	{
		if(b>0)cout<<"Q1";
		else cout<<"Q4";
	}
}
