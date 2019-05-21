#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	int t;
	double a, b, c, da, db, dc, s, r, m;
	cin>>t;
	while(t--)
	{
		cin>>a>>da>>db>>dc;
		s = 3.0*a*da/2.0;
		b = 2.0*s/3.0/db;
		c = 2.0*s/3.0/dc;
		r = a*b*c/4.0/s;
		m = 4.0*(r*r-(a*a+b*b+c*c)/9.0);
		m = (m<0.0) ? 0.0 : m;
		cout<<fixed<<setprecision(3)<<s<<" "<<sqrt(m)<<'\n';
	}
	return 0;
}
