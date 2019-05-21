#include<fstream>
using namespace std;

int a[101][101],n;

ifstream fin("royfloyd.in");
ofstream fout("royfloyd.out");

void citire()
{
	int i,j;
	fin>>n;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	fin>>a[i][j];
}

void royfloyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(a[i][k] && a[k][j] && (a[i][j]>a[i][k]+a[k][j] || !a[i][j]) && i!=j) a[i][j]=a[i][k]+a[k][j];
}

void afisare()
{
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		fout<<a[i][j]<<" ";
		fout<<"\n";
	}
}

int main()
{
	citire();
	royfloyd();
	afisare();
	return 0;
}
