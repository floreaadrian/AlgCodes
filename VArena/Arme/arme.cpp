#include<fstream>

using namespace std;

ifstream fin("arme.in");
ofstream fout("arme.out");

int v[2001];

int main()
{
	int n,m,s,i,u,p,max;
	fin>>n>>m;
	for(i=0;i<n+m;i++)
	fin>>v[i];
	fin.close();
	for(u=m+n-1;u>0;u--)
	{
		max=v[0];
		p=0;
		for(i=1;i<=u;i++)
		if(v[i]>max){
			max=v[i];
			p=i;
		}
		v[p]=v[u];
		v[u]=max;
	}
	s=0;
	for(i=m+n-1;i>=m;i--)
	s+=v[i];
	fout<<s;
	fout.close();
	return 0;
}
