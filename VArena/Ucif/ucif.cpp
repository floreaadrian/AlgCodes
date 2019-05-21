#include<fstream>

using namespace std;

ifstream fin("ucif.in");
ofstream fout("ucif.out");

int main()
{
	int n,i,j,s,p;
	fin>>n;
	s=0;
	for(i=1;i<=n;i++)
	{
		p=1;
		for(j=0;j<i;j++)
		p=(p*i)%10;
		s+=p;
	}
	fout<<s%10;
	return 0;
}
