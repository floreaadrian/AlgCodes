#include<iostream>
using namespace std;
int prim(int n,int d)
{
if(d==1) return 1;
else
if(n%d==0) return 0;
else
return prim(n,d-1);
}
int main()
{
	int v[201],n,ok=1,c=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>v[i];
	if(prim(v[n],v[n]/2)==1)ok=0;
	if(ok)
	for(int i=1;i<=n;i++){
		if(prim(v[n],v[n]/2)==0)c++;
	}else{
	for(int i=1;i<=n;i++){
		if(prim(v[n],v[n]/2)==1)c++;
	}	
	}
	cout<<c;
}
