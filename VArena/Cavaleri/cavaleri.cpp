#include<fstream>

using namespace std;

ifstream fin("cavaleri.in");
ofstream fout("cavaleri.out");

int main()
{
	int i,n,x,p,zi,minzi,mincav,sp,suma,cf;
	fin>>x>>n;
	minzi=x+1;
	mincav=-1;
	for(i=0;i<n;i++)
	{
		fin>>p;
		zi=1;
		while(p<x)
		{
			zi++;
			sp=p;
			do{
				suma=0;
				while(sp>0)
				{
					cf=sp%10;
					sp/=10;
					suma+=cf*cf;
				}
				sp=suma;
			}while(sp>9);
			if(sp==1)
			p=p+p;
			else
			p++;
		}
		if(zi<minzi)
		{
			minzi=zi;
			mincav=i;
		}
	}	
	fin.close();
	fout<<mincav+1<<" "<<minzi;
	fout.close();
	return 0;
}
