#include <iostream>

using namespace std;

void citire(int &n,int x[]){
	n=1;
	cin>>x[n];
	while(x[n]!=0){
		n++;
		cin>>x[n];
	}
	n--;
}

bool asem(int a,int b)
{
	int k[10]={0},k1[10]={0};
	while(a)
	{
		k[a%10]=1;
		a/=10;
	}
	while(b)
	{
		if(k[b%10]==0) return false;
		k1[b%10]=1;
		b/=10;
	}
	for(int i=0;i<=9;++i)
		if(k[i]!=k1[i])return false;
	return true;
}

void eliminare_numar(int &n,int l,int x[])
{
	for(int i=l;i<n;i++)
		x[i]=x[i+1];
	x[n]=0;
	n--;
}

bool exista(int m,int a,int r[])
{
	for(int i=1;i<=m;++i)
		if(r[i]==a)return true;
	return false;
}

void rezolvare(int &n,int &m,int x[],int r[])
{
	int i=1;
	m=0;
	bool ok=false;
	while(i<=n)
	{
		int j=i+1;
		ok=false;
		while(j<=n)
		{
			if(asem(x[i],x[j])){
				if(!ok && !exista(m,x[i],r)){m++;r[m]=x[i];}
				if(!exista(m,x[j],r)){m++;
				r[m]=x[j];}
				ok=true;
				eliminare_numar(n,j,x);
			}else ok=false;
			if(!ok)j++;
		}
		if(ok)eliminare_numar(n,i,x);
		i++;
	}
}

void afisare(int m,int y[])
{
	if(m==0)cout<<"Sirul R e vid";
	else
	for(int i=1;i<=m;++i)
		cout<<y[i]<<" ";
}

int main()
{
	int n,x[10005];
	citire(n,x);
	int m,r[10005];
	rezolvare(n,m,x,r);
	afisare(m,r);
	return 0;
}
