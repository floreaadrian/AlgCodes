#include<fstream>
using namespace std;
ifstream fin("secvbest.in");
ofstream fout("secvbest.out");

int main()
{
	int a[100000],sum[100000],i,j,s,n,k;
	fin>>n>>k>>s;
	for(i=1;i<=n;++i)
	fin>>a[i];
	for(i=1;i<=n;++i)
	{
		sum[i]+=a[i];
	}
	for(i=1;i<=n;++i)
	{
		fout<<sum[i]<<" ";
	}
	
}
