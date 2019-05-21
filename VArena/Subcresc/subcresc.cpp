#include<fstream>

using namespace std;

ifstream fin("subcresc.in");
ofstream fout("subcresc.out");

int main()
{
	int lmx=1,i,n,a,b,l=1;
	fin>>n>>b;
	for(i=2;i<=n;i++)
	{
		fin>>a;
		if(b<=a)
		{
			l++;
			if(lmx<l)lmx=l;
		}else l=1;
		b=a;
	}
	fout<<lmx;
	return 0;
}
