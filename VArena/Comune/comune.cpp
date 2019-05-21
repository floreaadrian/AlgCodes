#include<fstream>

using namespace std;

ifstream fin("comune.in");
ofstream fout("comune.out");

int main()
{
	int n,n1,m,m1,cfn,cfm,cfc=0,cf;
	fin>>n>>m;
	for(cf=0;cf<10;cf++)
	{
		cfn=0;
		n1=n;
		while(n1)
		{
			if(n1%10==cf)
			cfn++;
			n1/=10;
		}
		cfm=0;
		m1=m;
		while(m1)
		{
			if(m1%10==cf)
			cfm++;
			m1/=10;
		}
		if(cfm<cfn)
		cfc+=cfm;
		else
		cfc+=cfn;
	}
	fout<<cfc<<"\n";
	return 0;
}
