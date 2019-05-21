#include<fstream>
using namespace std;

ifstream fin("bmatrix.in");
ofstream fout("bmatrix.out");

int n,m,a[200][200],i,j,v[200],l=0,c=0;

void citire()
{
	fin>>n>>m;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	fin>>a[i][j];
}

void parcurgere()
{
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
	if(a[i][j]==0)
	{
		while(a[i][j]==0)
		{
			i++;c++;
		}
		while(a[i][j]==0)
		{
			j++;l++;
		}
	}
	fout<<c<<" "<<l<<"\n";
    }
}

int main()
{
	citire();
	parcurgere();
	return 0;
}
