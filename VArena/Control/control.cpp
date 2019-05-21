#include<fstream>

using namespace std;

ifstream fin("control.in");
ofstream fout("control.out");

int cutie[201];

int main()
{
	int n,d,nc,g,nzero,nunu,ng,npare;
	fin>>n;
	for(d=0;d<n;d++)
	{
		fin>>g;
		cutie[g]++;
	}
	nzero=nunu=ng=npare=0;
	for(g=1;g<=200;g++)
	{
		if(cutie[g]>0)
		{
			if(cutie[g]%2==0)
			npare++;
			ng++;
			if(ng==3)
			{
				if(npare==0 || npare==3)
				nunu++;
				else
				nzero++;
				ng=npare=0;
			}
		}
	}
	nc=nunu*10+nzero;
	d=2;
	while(d*d<=nc && nc%d>0)
	d++;
	if(d*d<=nc)
	fout<<nc<<"\n"<<0;
	else 
	fout<<nc<<"\n"<<1;
	return 0;
}
