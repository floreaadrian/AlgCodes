#include<fstream>
#include<string.h>
using namespace std;
ofstream fout("text.in");
ifstream fin("high_security.txt");
int v[3][10001],n;
void creare()
{
	string c;
	fin>>n;
	fin>>c;
	for(int i=0;i<n;i++)
	if(c[i]=='X')
	v[1][i]=-1;
	fin>>c;
	for(int i=0;i<n;i++)
	if(c[i]=='X')
	v[2][i]=-1;
}
int main()
{
	int a,sum,t,p;
	fin>>t;
	for(int jj=1;jj<=t;jj++)
	{
		creare();
		for(int i=1;i<=n;i++)
		{
			
		}
		for(int i=1;i<=2;i++)
		{
			for(int j=0;j<n;j++)
			fout<<v[i][j]<<" ";
			fout<<"\n";
		}
		memset(v,0,sizeof(v));
		fout<<"\n";
	}
	return 0;
}
