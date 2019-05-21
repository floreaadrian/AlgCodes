#include<fstream>

using namespace std;

ifstream fin("sao.in");
ofstream fout("sao.out");

int main()
{
	int n,m,r,p,c,RM1,PM1,rm=0,pm=0,mi=2000000001;
	fin>>n;
	for(int i=1;i<=n;i++)
	{
		fin>>RM1>>PM1;
		rm+=RM1;pm+=PM1;
	}
	fin>>m;
	for(int i=1;i<=m;i++)
	{
		fin>>r>>p>>c;
		if(r>=rm && p>=pm && c<mi)
		mi=c;
	}
	fout<<mi;
	return 0;
}
