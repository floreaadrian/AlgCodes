#include <iostream>

using namespace std;

void citire(int& n,int a[],int &ma)
{
	cin>>n;
	for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			if(a[i]>ma)ma=a[i];
		}
}

void gen_prim(int n,int nrprim[],int &k)
{
	bool prim[505];
	k=0;
	for(int i=2;i<=n;++i)
		prim[i]=true;
	for(int i=2;i<=n;++i)
		if(prim[i]){
			k++;
			nrprim[k]=i;
			for(int j=i+i;j<=n;j+=i)
			prim[j]=false;
		}
}

bool desc(int prim,int n)
{
	int k=0;
	while(n%prim==0){
		n/=prim;
		k++;
	}
	if(k==1) return true;
	return false;
}

void construire(int n,int a[],int y[],int &m,int ma)
{
	int nrprim[505],k;
	m=0;
	gen_prim(ma,nrprim,k);
	for(int i=1;i<=k;++i)
	{
		bool ok=true;
		for(int j=1;j<=n && ok;++j)
			if(desc(nrprim[i],a[j])){
				m++;
				y[m]=nrprim[i];
				ok=false;
			}
	}
}

void afisare(int m,int y[])
{
	if(m==0)cout<<"Sirul Y este vid";
	else
	for(int i=1;i<=m;++i)
		cout<<y[i]<<" ";
}

int main() {
	int n,m,ma=0,a[505],y[505];
	citire(n,a,ma);
	construire(n,a,y,m,ma);
	afisare(m,y);
	return 0;
}
