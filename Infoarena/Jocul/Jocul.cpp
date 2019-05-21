#include<fstream>
using namespace std;

ifstream fin("jocul.in");
ofstream fout("jocul.out");

int n,v[1001],i,s=0;

int main()
{
	fin>>n;
	for(i=1;i<=n;++i)
	{
	fin>>v[i];
	s+=v[i];
	}
	fout<<s/2;
}
