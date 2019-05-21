#include<fstream>

using namespace std;

ifstream fin("felinare.in");
ofstream fout("felinare.out");

int f[5001];

int main()
{
	int n,nrop,aprinse,i,i1,v;
	fin>>n;
	f[0]=0;
	for(i=1;i<n;i++)
	f[i]=1;
	nrop=1;
	aprinse=n-1;
	i=0;
	while(aprinse<n){
		i1=(i+1)%n;
		v=(f[i]+f[i1])%2;
		aprinse=aprinse+v-f[i1];
		f[i1]=v;
		nrop++;
		i=i1;
	}
	fout<<nrop;
	return 0;
}
