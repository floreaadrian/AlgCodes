#include<fstream>

using namespace std;

ifstream fin("cfdist.in");
ofstream fout("cfdist.out");

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
	for(i=0;i<10;i++)
	{
		if(fr[i]>0)
		c++;
	}
	fout<<c;
	fout.close();
	return 0;
}
