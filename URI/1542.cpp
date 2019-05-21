#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int q,d,p,n;
	bool ok=true;
	while(ok)
	{
	cin>>q>>d>>p;
	if(q==0)break;
	n=(d*p)/(p-q);
	cout<<(abs)(n*q)<<" paginas\n";
    }
}
