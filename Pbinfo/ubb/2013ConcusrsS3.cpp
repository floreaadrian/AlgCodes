#include <iostream>

using namespace std;

void citire(int& n,int a[])
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
}

bool lafel(int a,int b)
{
	if(a==b) return false;
	while(a<b)
	{
		b/=10;
	}
	if(a==b) return true;
	return false;
}

int cautdelai(int x,int a[],int n,int &mr)
{
	int ma=1;
	for(int i=x+1;i<=n;++i)
		if(lafel(a[x],a[i]))
			ma++,mr=i;
	return ma;
}

void construire(int n,int a[],int& st,int& dr,int &ma){
	int mr;
	for(int i=1;i<=n;++i)
	if(ma<cautdelai(i,a,n,mr)){
		ma=cautdelai(i,a,n,mr);
		st=i;
		dr=mr;
	}
}

void afisare(int y[],int st,int dr,int ma)
{
	if(ma==1)cout<<"Sirul Y este vid";
	else
	for(int i=st;i<=dr;++i)
		cout<<y[i]<<" ";
}

int main() {
	int n,ma=0,a[505],y[505],st,dr;
	citire(n,a);
	construire(n,a,st,dr,ma);
	afisare(a,st,dr,ma);
	return 0;
}
