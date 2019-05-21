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

int numere(int n)
{
	int s=0;
	while(n){
		s=s*10+n%10;
		n/=10;
	}
	return s;
}

bool verf(int n)
{
	if(numere(n)==n) return true;
	return false;
}

void inserare(int a,int &m,int y[])
{
	m++;
	for(int i=1;i<=m;++i)
	if(a==y[i]){m--;return;}
	else if(a>y[i]){
		for(int j=m;j>i;j--)
			y[j]=y[j-1];
		y[i]=a;
		return;
	}
	y[m]=a;
}

void construire(int n,int &m,int x[],int y[])
{
	for(int i=1;i<=n;++i)
	if(verf(x[i]))
		inserare(x[i],m,y);
}

void afisare(int m,int y[])
{
	if(m==0)cout<<"Sirul Y e vid";
	for(int i=1;i<=m;++i)
		cout<<y[i]<<" ";
}

int main()
{
	int n,x[10005];
	citire(n,x);
	int m,y[10005];
	construire(n,m,x,y);
	afisare(m,y);
	return 0;
}
