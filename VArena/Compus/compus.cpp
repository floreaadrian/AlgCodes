#include<fstream>
#include<iostream>

using namespace std;

ifstream fin("compus.in");
ofstream fout("compus.out");

int main()
{
	int i,j,aux,n,v[10001],e,p,i_n;
	fin>>n>>e>>p;
	for(i=0;i<n;i++)
	fin>>v[i];
	i=0;
	while(v[i]!=e)
	i++;
	for(i_n=i;i_n<n-1;i_n++)
	v[i_n]=v[i_n+1];
	for(i_n=n-1;i_n>p;i_n--)
	v[i_n]=v[i_n-1];
	v[p]=e;
	i=0;
	j=n-1;
	while(i<j)
	{
		aux=v[i];
		v[i]=v[j];
		v[j]=aux;
		i++;
		j--;
	}
	aux=v[0];
	for(i=1;i<n;i++)
	v[i-1]=v[i];
	v[n-1]=aux;
	for(i=0;i<n;i++)
	fout<<v[i]<<" ";
	fout<<"\n";
	return 0;
}
