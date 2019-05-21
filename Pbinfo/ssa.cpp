#include<fstream>
#include<math.h>
using namespace std;
ifstream fin("eureni.in");
ofstream fout("eureni.out");
int val[12],rez[12],n,s;
int main()
{
	int v[12],n,s,e;
	fin>>s>>n>>e;
	v[1]=1;
	for(int i=2;i<=n+1;i++)
	v[i]=pow(e,(i-1));
	int i=n,bani=s;
	while(bani>0 && i>0){
		int va=val[i];
		if(bani/va>0){
			rez[i]=bani/va;
			bani=bani%va;
		}
		i--;
	}
	for(int i=n;i>=1;i--)
	if(rez[i])
	fout<<val[i]<<" "<<rez[i]<<"\n";
	return 0;
}
