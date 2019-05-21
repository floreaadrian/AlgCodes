#include<iostream>
using namespace std;
int main()
{
	int d,vf,vg,d1,d2;
	while(!cin.eof())
	{
	cin>>d>>vf>>vg;
	d1=(12-d)*vf;
	d2=12*vg;
	if(d1<d2)
	cout<<"S\n";
	else cout<<"N\n";
}
}
