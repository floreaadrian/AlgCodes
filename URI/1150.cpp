#include<iostream>
using namespace std;
int main()
{
	int x,y,z,c=1;
	cin>>x>>z;y=x;
	while(z<=x)
	cin>>z;
	do
	{
		x++;
		c++;
		y+=x;
	}while(y<=z);
	cout<<c<<"\n";
}
