#include<iostream>
using namespace std;
int main()
{
	int x[1000],n,i,i_poz=0,mi;
	cin>>n;
	cin>>x[i];mi=x[i];
	for(i=1;i<n;++i)
	{
		cin>>x[i];
		if(x[i]<mi)
		{
			mi=x[i];
			i_poz=i;
		}
	}
	cout<<"Menor valor: "<<mi<<"\n";
	cout<<"Posicao: "<<i_poz<<"\n";
}
