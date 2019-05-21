#include <iostream>

using namespace std;

void citire(int x[],int &n)
{
	n=1;
	int a;
	cin>>a;
	while(a!=0)
	{
		x[n]=a;
		n++;
		cin>>a;
	}
}

int cifre(int nr){
	int k=0;
	while(nr){
		k=k*10+nr%10;
		nr/=10;
	}
	return k;
}

bool palindorm(int nr)
{
	int nr1=cifre(nr);
	if(nr==nr1) return true;
	return false;
}

void construire(int x[],int y[],int n,int &m)
{
	m=0;
	for(int i=1;i<=n;++i)
	if(palindorm(x[i])){
		//cout<<x[i]<<" ";
		m++;
		for(int j=m;j>=1;j--)
		if(x[i]>y[j]){
			y[j]=y[j-1];
			y[j-1]=x[i];
		}
	}
}

void afisare(int y[],int m)
{
	for(int i=1;i<=m;++i)
		cout<<y[i]<<" ";
}

int main() {
	int n,m;
	int x[1005],y[1005];
	citire(x,n);
	construire(x,y,n,m);
	afisare(y,m);
	return 0;
}
