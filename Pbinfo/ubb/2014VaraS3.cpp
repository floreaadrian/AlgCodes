#include <iostream>

using namespace std;

void construire(int n,int x[])
{
	int k=1,i=1;
	n=n*n*2;
	while(i<=n){
		x[i]=k;
		i++;
		for(int j=2;j<=k/2;++j)
			if(k%j==0){
				x[i]=j;
				i++;
			}
		k++;
	}
}

int prima(int a){
	while(a>9) a/=10;
	return a;
}

int ultima(int a){
	return a%10;
}

int maxima(int a){
	int ma=0;
	while(a>0){
		if(a%10>ma)ma=a%10;
		a/=10;
	}
	return ma;
}

void matrice(int a[][10],int n,int x[]){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i+j==n+1) a[i][j]=maxima(x[n*n+i*i]);
			else if(i+j<n+1) a[i][j]=ultima(x[n*n+i+j]);//deasupra
			else if(i+j>n+1) a[i][j]=prima(x[n*n+i+j]);//sub
}

int cmm(int a[][10],int n,int col)
{
	int fr[10]={0};
	int mare=0;
	for(int i=1;i<=n;++i)
		fr[a[i][col]]++;
	for(int i=9;i>=0;i--)
		while(fr[i]){
			mare=mare*10+i;
			fr[i]--;
		}
	return mare;
}

int main() {
	int n,x[163],a[10][10];
	cin>>n;
	construire(n,x);
	matrice(a,n,x);
	for(int i=1;i<=n;++i)
	cout<<cmm(a,n,i)<<" ";
	return 0;
}
