#include<fstream>

using namespace std;

ifstream fin("siruri1.in");
ofstream fout("siruri1.out");

int v[101],fr[32001];

int main()
{
	int k=1,n,i;
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>v[i];
		fr[v[i]]=1;
	}
	fin.close();
	k=1;
	for(i=0;i<32000;i++)
	{
		if(fr[i]==1)
		{
		fr[i]=k;
		k++;
		}
	}
	for(i=0;i<n;i++)
	fout<<fr[v[i]]<<" ";
	fout.close();
	return 0;
}
