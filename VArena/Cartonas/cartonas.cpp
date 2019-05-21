#include<fstream>

using namespace std;

ifstream fin("cartonas.in");
ofstream fout("cartonas.out");

int cart[100],nr1[100],poz[100];

int main()
{
	int n,x,i,suma,nivel,nivx,u,ind,minnr1,maxpoz;
	fin>>n>>x;
	for(nivel=0;nivel<n;nivel++){
		suma=0;
		for(i=0;i<n-nivel;i++){
			if(nivel==0)
			fin>>cart[i];
			else
			cart[i]+=cart[i+1];
			if(cart[i]==x)
			nivx=nivel+1;
			suma+=cart[i];
		}
		nr1[nivel]=0;
		while(suma>0){
			nr1[nivel]+=suma%2;
			suma/=2;
		}
		poz[nivel]=nivel+1;
	}
	fin.close();
	for(u=n-1;u>0;u--){
    minnr1=nr1[0];
    maxpoz=poz[0];
    ind=0;
    for(i=1;i<=u;i++)
      if(nr1[i]<minnr1 || (nr1[i]==minnr1 && poz[i]>maxpoz)) {
        minnr1=nr1[i];
        maxpoz=poz[i];
        ind=i;
      }
    nr1[ind]=nr1[u];
    nr1[u]=minnr1;
    poz[ind]=poz[u];
    poz[u]=maxpoz;
    }
	fout<<cart[0]<<"\n"<<nivx<<"\n";
	for(i=0;i<n;i++)
	fout<<poz[i]<<" ";
	fout<<"\n";
	fout.close();
	return 0;
}
