#include<fstream>

using namespace std;

ifstream fin("cyber.in");
ofstream fout("cyber.out");

int nr[3];

int main()
{
	int n,i,d,p,d1,maxd,aux;
	fin>>n>>nr[0];
	for(i=1;i<n;i++){
		fin>>nr[i];
		if(nr[i]<nr[0]){
			aux=nr[0];
			nr[0]=nr[i];
			nr[i]=aux;
		}
	}
	fin.close();
	aux=nr[1]-nr[0];
	maxd=1;
	d=1;
	while(d*d<=aux && d<=nr[0] && maxd<=d){
		if(aux%d==0){
			if((n<3) || (nr[2]%d==nr[0]%d))
			maxd=d;
			d1=aux/d;
			if(d1<=nr[0] && ((n<3) || (nr[2]%d1==nr[0]%d1)))
			maxd=d1;
		}
		d++;
	}
	if(maxd%2==0)
	  p=maxd-1;
	else
	  p=maxd;
	d=3;
	while(d*d<=p && p>2){
		d=3;
		while(d*d<=p && p%d>0)
		d+=2;
	  p--;
	}
	p++;
	if(p<=2){
		if(2<=maxd)
		p=2;
		else
		p=0;
	}
	fout<<maxd<<"\n"<<p;
	fout.close();
	return 0;
}
