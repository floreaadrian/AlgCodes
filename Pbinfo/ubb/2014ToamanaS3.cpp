#include <iostream>

using namespace std;

void citire(int n,int a[][51])
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
}

void afisare(int n,int a[][51])
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
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

bool superprim(int n)
{
	int k=n,c=0;
	int p10=1;
	while(k)
	{
		k/=10;
		c++;
	}
	if(verfprim(n)) return true;
	for(int i=1;i<c;++i)
	p10*=10;
	for(int i=1;i<c;++i)
	{
		n=(n%10)*p10+n/10;
		if(verfprim(n)) return true;
	}
	return false;
}

void interschimbare_sup_inf(int a[][51],int n)
{
	for(int i=1;i<=n/2;++i)
		for(int j=1;j<=n;++j)
			if(i<j && i+j<n+1)
			{
				int aux=a[i][j];
				a[i][j]=a[n-i+1][j];
				a[n-i+1][j]=aux;
			}
}

void interschimbare_dr_st(int a[][51],int n)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n/2;++j)
			if(i>j && i+j<n+1)
				if(superprim(a[i][j]) && superprim(a[i][n-j+1])){
					int aux=a[i][j];
					a[i][j]=a[i][n-j+1];
					a[i][n-j+1]=aux;
				}

}

int main() {
	int n,a[51][51];
	cin>>n;
	citire(n,a);
	interschimbare_sup_inf(a,n);
	interschimbare_dr_st(a,n);
	afisare(n,a);
	return 0;
}
