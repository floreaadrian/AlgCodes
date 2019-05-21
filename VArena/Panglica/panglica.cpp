#include<fstream>

using namespace std;

ifstream fin("panglica.in");
ofstream fout("panglica.out");

int prim[200],ultim[200];

int main()
{
	int n,i,c,cul,cmax,lungime,lmax;
	fin>>n>>c;
	for(i=0;i<n;i++)
	{
		fin>>cul;
		if(prim[cul-1]==0)
		prim[cul-1]=i+1;
		ultim[cul-1]=i+1;
	}
	lmax=0;
	for(cul=0;cul<c;cul++)
	{
		if(prim[cul]>0)
		lungime=ultim[cul]-prim[cul]+1;
		if(lungime>lmax){
		lmax=lungime;
		cmax=cul;
		}
	}
	fout<<lmax<<"\n"<<cmax+1<<"\n"<<prim[cmax]-1<<"\n"<<n-ultim[cmax]<<"\n";
	return 0;
}
