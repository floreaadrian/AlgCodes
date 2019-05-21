#include<fstream>

using namespace std;

ifstream fin("jimjam.in");
ofstream fout("jimjam.out");

int main()
{
	int a,b,z,d,dist,zile;
	fin>>a>>b>>z>>d;
	fin.close();
	dist=z/2*(a-b)+(z%2)*a;
	if(a==b)
		if(a==d)
		zile=1;
		else
		zile=0;
	else if((d-a>=0) && ((d-a)%(a-b)==0))
	zile=1+2*(d-a)/(a-b);
	else if(d%(a-b)==0)
	zile=2*d/(a-b);
	else 
	zile=0;
	fout<<dist<<" "<<zile;
	fout.close();
	return 0;
}
