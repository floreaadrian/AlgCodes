#include <iostream>

using namespace std;

struct sir{
	int nr;
	int fr;
} y[505];

void citire(int& n,int a[])
{
	int x;
	n=0;
	cin>>x;
	while(x!=0){
		n++;
		a[n]=x;
		cin>>x;
	}
}

bool verfprim(int n)
{
	if(n==1)return false;
	if(n%2==0 && n>2)return false;
	int d=3;
	while(d*d<=n)
	{
		if(n%d==0)return false;
		d++;
	}
	return true;
}

int sumcifre(int n)
{
	int s=0;
	while(n)
	{
		s+=n%10;
		n/=10;
	}
	return s;
}

void inserare(int x,sir y[],int &m){
	for(int i=1;i<m;++i)
	if(x==y[i].nr){m--;return;}
	else if(y[i].nr>x){
		for(int j=m;j>i;j--)
		{
			y[j]=y[j-1];
		}
		y[i].nr=x;
		return;
	}
	y[m].nr=x;
}

void construire(int n,int &m,int a[],sir y[]){
	int frecv[37]={0};
	m=0;
	for(int i=1;i<=n;++i)
	{
		int sum=sumcifre(a[i]);
		if(verfprim(sum)){
				frecv[sum]++;
				m++;
				inserare(a[i],y,m);
		}
	}
	for(int i=1;i<=m;++i)
		y[i].fr=frecv[sumcifre(y[i].nr)];
}

void afisare(int m,sir y[]){
	if(m==0) cout<<"Sirul Y este vid";
	else
	for(int i=1;i<=m;++i)
		cout<<y[i].nr<<" "<<y[i].fr<<" ";
}

int main() {
	int n,m,a[505];
	citire(n,a);
	construire(n,m,a,y);
	afisare(m,y);
	return 0;
}
