#include<fstream>

using namespace std;

ifstream fin("cuart.in");
ofstream fout("cuart.out");

int ncuart[2],primul[2];

int main()
{
	int n,p,i,pas,x,xc,maxns,scris,p10,suma,k,rez,copil,val;
	fin>>p>>n;
	maxns=0;
	for(pas=0;pas<2;pas++)
	for(i=0;i<n;i++)
	{
		fin>>x;
		xc=x;
		scris=0;
		p10=1;
		while(xc>0){
			if(xc%2==1-pas){
				scris+=(xc%10)*p10;
				p10*=10;
			}
			xc/=10;
		}
		if(scris==0){
			if(x>maxns)
			maxns=x;
		}else{
			suma=k=1;
			while(suma+k+4<=scris){
				k+=4;
				suma+=k;
			}
			if(suma==scris)
			ncuart[pas]++;
			if(primul[pas]==0)
			primul[pas]=scris;
		}
	}
	fin.close();
	if(ncuart[0]>ncuart[1]){
		copil=1;
		val=ncuart[0];
	}else if(ncuart[0]<ncuart[1]){
		copil=2;
		val=ncuart[1];
	}else if(primul[0]>primul[1]){
		copil=1;
		val=primul[0];	
	}else if(primul[0]<primul[1]){
		copil=2;
		val=primul[1];	
	}else
		copil=val=0;
	if(p==1)
	  rez=maxns;
	else if(p==2)
	  rez=copil;
	else
	  rez=val;
	fout<<rez;
	fout.close();
	return 0;
}
