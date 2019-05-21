#include<fstream>
using namespace std;
ifstream fin("reactivi.in");
ofstream fout("reactivi.out");
int ti[80001],tf[80001],n;
int main()
{
	int nf,miny,maxx,icy,icx,max,i,j,poz;
	fin>>n;
	for(i=0;i<n;i++)fin>>ti[i]>>tf[i];
	for(i=n-1;i>0;i--)
	for(poz=i,j=0;j<i;j++){
		if(ti[j]>ti[poz] || ti[j]==ti[poz] && tf[j]<tf[poz]) poz=j;
		max=ti[poz];ti[poz]=ti[j];ti[j]=max;
		max=tf[poz];tf[poz]=tf[j];tf[j]=max;
	}
	nf=1;icx=ti[0];icy=tf[0];
	for(i=1;i<n;i++){
		miny=icy; if(miny>tf[i]) miny=tf[i];
		maxx=icx; if(maxx<ti[i]) maxx=ti[i];
		if(maxx<=miny){
			icx=maxx;icy=miny;
		}else{
			nf++;
			icx=ti[i];icy=tf[i];
		}
	}
	fout<<nf<<"\n";
	return 0;
}
