#include<fstream>

using namespace std;

ifstream fin("rotk.in");
ofstream fout("rotk.out");

int v[200001];

void rotire(int i,int j,int v[])
{
	int aux;
	while (i<j) {
    aux=v[i];
    v[i]=v[j];
    v[j]=aux;
    i++;
    j--;
    }
}

int main()
{
	int n,n1,n2,k,k1,k2,i,j;
	fin>>n1;
	for(i=0;i<n;i++)
	fin>>v[i];
	fin>>k1;
	fin>>n2;
	for(i=0;i<n2;i++)
	fin>>v[i+n1];
	fin>>k2;
	fin>>k;
	n=n1+n2;
	i=0;
	j=n1-1;
	rotire(i,j,v);
	i=0;
	j=n1-k1-1;
	rotire(i,j,v);
	i=n1-k1;
    j=n1-1;
    rotire(i,j,v);
    i=n1;
    j=n-1;
    rotire(i,j,v);
    i=n1;
    j=n-k2-1;
    rotire(i,j,v);
    i=n-k2;
    j=n-1;
    rotire(i,j,v);
    i=0;
    j=n-1;
    rotire(i,j,v);
    i=0;
    j=n-k-1;
    rotire(i,j,v);
    i=n-k;
    j=n-1;
    rotire(i,j,v);
    for(i=0;i<n;i++)
    fout<<v[i]<<" ";
    fout<<"\n";
	return 0;
}
