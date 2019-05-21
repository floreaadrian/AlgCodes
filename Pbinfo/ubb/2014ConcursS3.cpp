#include <iostream>

using namespace std;

void citire(int n,int a[][51])
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
}

void afisare(int n,int a[])
{
	if(n==0) cout<<"Sirul este vid";
	else
	for(int i=1;i<=n;++i)
		cout<<a[i]<<" ";
}

bool verfprim(int n)
{
	if(n==1) return false;
	if(n%2==0 && n>2) return false;
	int d=3;
	while(d*d<=n)
	{
		if(n%d==0) return false;
		d++;
	}
	return true;
}

bool superprim(int a)
{
	while(a)
	{
		if(!verfprim(a)) return false;
		a/=10;
	}
	return true;
}

void inserare(int x[],int& m,int a)
{
	m++;
	for(int i=1;i<=m;++i)
	if(a==x[i]){m--;return;}
	else if(x[i]<a){
		for(int j=m;j>i;--j)
		{
			int aux=x[j];
			x[j]=x[j-1];
			x[j-1]=aux;
		}
		x[i]=a;
		return;
	}
	x[m]=a;
}

int main() {
	int n,a[51][51],x[51],m=0;
	cin>>n;
	citire(n,a);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if((i>j && i+j<n+1) || (i<j && i+j>n+1))
			{
				if(superprim(a[i][j]))
				inserare(x,m,a[i][j]);
			}
	afisare(m,x);
	return 0;
}
