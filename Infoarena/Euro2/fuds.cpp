#include<fstream>
#include<iostream>
using namespace std;

ifstream fin("euro2.in");
ofstream fout("euro2.out");

int main()
{
	int n,i,j,i_1,indice;
	float a[100000],ma=0;
	long lung[100000],urm[100000],maxim=0,minim=0;
	fin>>n;
	for(i=1;i<=n;++i)
	{
	fin>>a[i];
    if((float)a[i]>ma){
	ma=a[i];i_1=i;
	}
	}
	for(i=1;i<=i_1;i++)
	{
		if(a[i]<a[i+1])
		maxim++;
	}
	for(j=i_1;j<=n;++j)
	{
		if(a[j]>a[j+1])
		minim++;
	}
	//cout<<minim;
	fout<<maxim+minim;
}
