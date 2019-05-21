#include<iostream>
#include<math.h>

using namespace std;

void tra(float x)
{
	float i;
	i=x-floor(x);
	i=i*100;
	int b,c;
	b=i;
	c=x;
	cout<<c<<","<<b<<"\n";
}

int main()
{
	int a,b,c,d,n;
	float re;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a>>b>>c>>d;
		re=(float)(b-d)/(a-c);
		tra(re);
	}
	return 0;
}
