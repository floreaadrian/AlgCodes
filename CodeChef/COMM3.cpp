#include<iostream>
#include<math.h>

using namespace std;

struct poc{
	int a,b;
};

float dis(poc x,poc y)
{
	float m;
	m=sqrt(pow(y.a-x.a,2)+pow(y.b-x.b,2));
	return m;
}

int main()
{
	poc k1,k2,k3;
	int t,r,n;
	cin>>t;
	for(int f=1;f<=t;++f)
	{
		int c=0;
		cin>>r;
		cin>>k1.a>>k1.b;
		cin>>k2.a>>k2.b;
		cin>>k3.a>>k3.b;
		if(dis(k1,k2)<=r)
		c++;
		if(dis(k2,k3)<=r)
		c++;
		if(dis(k3,k1)<=r)
		c++;
		if(c<2)
		cout<<"no\n";
		else
		cout<<"yes\n";
	}
	return 0;
}
