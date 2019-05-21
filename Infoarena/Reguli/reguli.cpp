#include<fstream>
using namespace std;
ifstream fin("reguli.in");
ofstream fout("reguli.out");
const int maxn=500005;
long long n,a[maxn],pr[maxn],k;
int main()
{
	fin>>n;
	for(int i=1;i<=n;i++)
	fin>>a[i];
	for(int i=2;i<=n;i++)
	a[i-1]=a[i]-a[i-1];
	n--;
	pr[1]=0;
	for(int i=2;i<=n;++i){
		while(k>0 && a[k+1]!=a[i])
		k=pr[k];
		if(a[k+1]==a[i])
		++k;
		pr[i]=k;
	}
	fout<<n-pr[n]<<"\n";
	for(int i=1;i<=n-pr[n];i++)
	fout<<a[i]<<"\n";
	return 0;
}
