#include<fstream>

using namespace std;

ifstream fin("culori1.in");
ofstream fout("culori1.out");

int v[1000],f[101];

int main()
{
	int n,i,k,j,i0=0,i1=1,i2=2,lafel=0,max;
	fin>>n>>k;
	for(i=0;i<n;i++)
	fin>>v[i];
	fin.close();
	for(i=0;i<n;i++)
	{
		if(v[i0]==v[i1] && v[i1]==v[i2])
		lafel++;
		i0=i1;
		i1=i2;
		i2=(i2+1)%n;
	}
	f[v[n-1]]++;
	for(i=0;i<(k-1);i++)
	f[v[i]]++;
	max=0;
	for(j=1;j<=100;j++)
	if(f[j]>max)
	max=f[j];
	i0=n-1;
	i1=k-2;
	for(i=0;i<n;i++)
	{
		f[v[i0]]--;
		i0=(i0+1)%n;
		i1=(i1+1)%n;
		f[v[i1]]++;
		if(f[v[i1]]>max)
		max=f[v[i1]];
	}
	fout<<lafel<<"\n"<<max;
	fout.close();
	return 0;
}
