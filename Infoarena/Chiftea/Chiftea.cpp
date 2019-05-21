#include<fstream>
#include<math.h>
using namespace std;

ifstream fin("chiftea.in");
ofstream fout("chiftea.out");

int main()
{
	int n,i,a,r;
	double s;
	fin>>n;
	for(i=1;i<=n;++i)
	{
		fin>>a;
		s=sqrt(a);
		if(s==(int)s)
		r=4*s; else {
		if(a%2==0)
		r=(4*(int)(s))+2;else
		r=(4*(int)(s))+4;
		}
		fout<<r<<"\n";
	}
}
