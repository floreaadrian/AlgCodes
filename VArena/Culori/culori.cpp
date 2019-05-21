#include<fstream>

using namespace std;

ifstream fin("culori.in");
ofstream fout("culori.out");

int fr[99];

int main()
{
	int n,i,c=0;
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>c;
		fr[c]++;
	}
	fin.close();
	for(i=0;i<=99;i++)
	{
		if(fr[i]>0)
		for(int j=1;j<=fr[i];j++)
		fout<<i<<" ";
	}
	fout<<"\n";
	fout.close();
	return 0;
}
