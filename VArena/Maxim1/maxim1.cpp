#include<fstream>
#include<limits.h>

using namespace std;

ifstream fin("maxim1.in");
ofstream fout("maxim1.out");

int cifre[3000];

int main()
{
	int a,b,c,d,nrcf,len,cf[6];
	int i,j,acopy,max,pos,nrap;
	fin>>a>>b>>c>>d;
	fin.close();
	nrcf=0;
	for(;a<=b;a++)
	{
		acopy=a;
		len=0;
		while(acopy>0){
			cf[len++]=acopy%10;
			acopy/=10;
		}
		while(len>0)
		cifre[nrcf++]=cf[--len];
	}
	fout<<cifre[c-1]<<"\n";
	nrap=0;
	while((c>0) && (c<nrcf)){
		max=cifre[pos=0];
		for(i=1;i<=c;i++)
		if(max<cifre[i])
		max=cifre[pos=i];
		c-=pos;
		fout<<max;
		for(i=0,j=pos+1;j<nrcf;i++,j++)
		cifre[i]=cifre[j];
		nrcf-=(pos+1);
		if(max==d)
		nrap++;
	}
	if(c==0)
	for(i=0;i<nrcf;i++){
		fout<<cifre[i];
		if(cifre[i]==d)
		nrap++;
	}
	fout<<"\n"<<nrap<<"\n";
	fout.close();
	return 0;
}
