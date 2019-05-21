#include<fstream>

using namespace std;

ifstream fin("cub1.in");
ofstream fout("cub1.out");

int cul[11],max1[50],v[50];

int main()
{
	int n,i,i1,i2,nrcul,culmax,l,lmax,dmax;
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>v[i];
		cul[v[i]]++;
	}
	fin.close();
	nrcul=0;
	culmax=0;
	for(i=0;i<11;i++)
	{
		if(cul[i]>0)
		nrcul++;
		if(cul[i]>culmax)
		culmax=cul[i];
	}
	fout<<nrcul<<"\n";
	for(i=0;i<11;i++)
	if(cul[i]==culmax)
	fout<<i<<" ";
	fout<<"\n";
	dmax=1;
	for(i=0;i<n;i++)
	{
		lmax=1;
		l=1;
		i1=0;
		if(i1==i)
		i1++;
		for(i2=i1+1;i2<n;i2++){
			if(i2!=i){
				if(v[i2]==v[i1]){
					l++;
					if(l>lmax)
					lmax=l;
				}else
				l=1;
				i1=i2;
			}
		}
		max1[i]=lmax;
		if(lmax>dmax)
		dmax=lmax;
	}
	fout<<dmax<<"\n";
	for(i=0;i<n;i++)
	if(max1[i]==dmax)
	fout<<i+1<<" ";
	fout<<"\n";
	fout.close();
	return 0;
}
