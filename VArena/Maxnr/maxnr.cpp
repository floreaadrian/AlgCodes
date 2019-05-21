#include<fstream>

using namespace std;

ifstream fin("maxnr.in");
ofstream fout("maxnr.out");

int fr[9];

int main()
{
	int n,i,c=0;
	fin>>n;
	fin.close();
	while(n)
	{
		fr[n%10]++;
		n/=10;
	}
	for(i=9;i>=0;i--)
	{
		if(fr[i]>0)
		for(int j=1;j<=fr[i];j++)
		fout<<i;
	}
	fout<<"\n";
	fout.close();
	return 0;
}
