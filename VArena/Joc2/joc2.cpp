#include<fstream>
#include<math.h>

using namespace std;

ifstream fin("joc2.in");
ofstream fout("joc2.out");

int frecv[10];
int apar[60001];

int main()
{
	int n,i,cf,ncul,lat,nrcf,afisate;
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>cf;
		frecv[cf]++;
	}
	fin.close();
	ncul=0;
	for(cf=0;cf<10;cf++)
	{
		if(frecv[cf]>0){
			ncul++;
			apar[frecv[cf]]=cf+1;
		}
	}
	lat=sqrt(n);
	fout<<ncul<<"\n"<<lat<<"\n";
	i=60000;
	afisate=0;
	while(afisate<lat*lat){
		while(apar[i]==0)
		i--;
		nrcf=i;
		while(nrcf>0 && afisate<lat*lat){
			fout<<apar[i]-1;
			afisate++;
			if(afisate%lat==0)
			fout<<"\n";
			nrcf--;
		}
		i--;
	}
	fout.close();
	return 0;
}
