#include<fstream>

using namespace std;

ifstream fin("multimi.in");
ofstream fout("multimi.out");

int main()
{
	int ina,inb,a,b,n,i=1;
	fin>>n;
	fin>>ina>>inb;
	while(i<n && ina<=inb)
	{
		fin>>a>>b;
		if(a>ina)ina=a;
		if(b<inb)inb=b;
		i++;
	}
	if(ina>inb)
	fout<<"multimea vida\n";
	else
	for(i=ina;i<=inb;i++)
	fout<<i<<" ";
	return 0;
}
