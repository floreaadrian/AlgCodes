#include<fstream>
#include<math.h>

using namespace std;

ifstream fin("cartier.in");
ofstream fout("cartier.out");

int prim[13001],ultim[13001];

int main(){
	int n,i,ncub,h,hmax,nhmax,s,d1,d2,lmax;
	hmax=0;
	nhmax=0;
	s=0;
	fin>>n;
	for(i=1;i<=n;i++){
		fin>>ncub;
		h=sqrt(ncub);
		while(ncub%h>0)
		h--;
		h=ncub/h;
		if(h>hmax){
			hmax=h;
			nhmax=1;
		}else if(h==hmax)
		nhmax++;
		s+=ncub/h;
		for(d1=2;d1*d1<=h;d1++){
			if(h%d1==0){
				if(prim[d1]==0)
				prim[d1]=i;
				ultim[d1]=i;
				d2=h/d1;
				if(prim[d2]==0)
				prim[d2]=i;
				ultim[d2]=i;
			}
		}
		if(h>1){
			if(prim[h]==0)
			prim[h]=i;
			ultim[h]=i;
		}
	}
	fin.close();
	lmax=0;
	for(d1=2;d1<=13000;d1++)
	if(ultim[d1]-prim[d1]>lmax)
	lmax=ultim[d1]-prim[d1];
	fout<<nhmax<<"\n"<<s<<"\n"<<lmax+1;
	fout.close();
	return 0;
}
