#include <iostream>

using namespace std;

bool prim(int n){
	if(n==1) return false;
	if(n>2 && n%2==0) return false;
	int d=3;
	while(d*d<=n){
		if(n%d==0) return false;
		d++;
	}
	return true;
}

int nr_prim(int k){
	int ac=2,nr=1;
	while(nr<k){
		ac++;
		while(!prim(ac))ac++;
		nr++;
	}
	return ac;
}

void afisare(int n,int a[][1005])
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}

int main()
{
	int n,a[1005][1005];
	cin>>n;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	if(i==j) a[i][j]=0;
	else if(i>j) a[i][j]=i;
	else if(i<j) a[i][j]=nr_prim(i);
	afisare(n,a);
	return 0;
}
