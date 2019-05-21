#include<fstream>
#include<math.h>

using namespace std;

ifstream fin("lapte.in");
ofstream fout("lapte.out");

int min(int a,int b)
{
	if(a<b)return a;
	return b;
}

int optim[101],sol;

int main()
{
	int n,t,l,x[101],y[101];
	fin>>n>>l;
	for(int i=1;i<=n;++i)
	fin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	  for(int j=l-x[i];j>=0;j--)
	  {
	  	if(optim[j+x[i]]<=optim[j]+y[j])
	  	optim[j+x[i]]=optim[j]+y[j];
	  	sol=max(sol,optim[j+x[i]]);
	  }
	  fout<<sol;
	  return 0;
}
