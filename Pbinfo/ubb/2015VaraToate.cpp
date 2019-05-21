//S1-a)
int func(int m,int n,int a[][51])
{
	int nr=0;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
		{
			int micol=50000;
			int milin=50000;
			int macol=0;
			int malin=0;
			for(int k=1;k<=m;++k)
				if(a[k][j]<micol)micol=a[k][j];
				else if(a[k][j]>macol)macol=a[k][j];
			for(int k=1;k<=n;++k)
				if(a[i][k]<milin)milin=a[i][k];
				else if(a[i][k]>malin)macol=a[i][k];
			if((micol==a[i][j] && malin==a[i][j]) || (milin==a[i][j] && macol==a[i][j]))
				cout<<a[i][j]<<" ",nr++;
		}
	return nr;
}
//
//
//
//
//
//S1-b)
int fucnmax(int n)
{
	int k=n,c=0;
	while(k){
		k/=10;
		c++;
	}
	int p10=1;
	for(int i=1;i<c;++i)
		p10*=10;
	int ma=n;
	for(int i=1;i<c;++i)
	{
		n=(n%10)*p10+n/10;
		if(n>ma)ma=n;
	}
	return ma;
}
//
//
//
//
//
//S1-c)
void iter(int n,int x[],int &v)
{
	for(int i=1;i<=n;++i)
		if(x[i]==v)
			{v=x[i];return;}
	v=-1;
}

void rec(int n,int x[],int &v)
{
	if(n==0) {v=-1;return;}
	if(x[n]==v) {v=n;return;}
	rec(n-1,x,v);
}
//
//
//
//
//S3
#include <iostream>

using namespace std;

void citire(int n,int m,int a[][101])
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
}

void construire(int n,int m,int a[][101],int x[])
{
	int k=1;
	for(int j=1;j<=m;++j)
	{
		for(int i=1;i<=n;++i)
			x[k]=a[i][j],k++;
	}
}

bool prim(int n)
{
	if(n==1)return false;
	if(n%2==0 && n>2) return false;
	int d=3;
	while(d*d<=n)
	{
		if(n%d==0) return false;
		d++;
	}
	return true;
}

bool magic(int n)
{
	int k=n*10,p10=10;
	while(k>9)
	{
		if(!prim(n%p10)) return false;
		p10*=10;
		k/=10;
	}
	if(!prim(k)) return false;
	return true;
}

int delai(int n,int k,int x[])
{
	int act=0;
	for(int i=k;i<n;++i)
		if(magic(x[i]+x[i+1]))act++;
		else return act;
	return act;
}

void rezolvare(int n,int m,int x[],int &st,int &ma)
{
	for(int i=1;i<=n*m;++i)
	{
		int act=delai(n*m,i,x);
		if(act>ma){
			ma=act;
			st=i;
		}
	}
}

void tiparire(int x[],int st,int ma)
{
	for(int i=st;i<=st+ma;++i)
	cout<<x[i]<<" ";
}

int main() {
	int n,m,a[101][101],x[10002],st=0,ma=0;
	cin>>n>>m;
	citire(n,m,a);
	construire(n,m,a,x);
	rezolvare(n,m,x,st,ma);
	tiparire(x,st,ma);
	return 0;
}
