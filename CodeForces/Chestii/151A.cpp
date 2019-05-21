#include<iostream>
using namespace std;
int main()
{
	int n,k,l,c,d,p,nl,np,ras,suc=0,lamai=0,sare=0;
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	cout<<min(min(k*l/nl,p/np),c*d)/n;
}
