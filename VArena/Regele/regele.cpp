#include<fstream>

using namespace std;

ifstream fin("regele.in");
ofstream fout("regele.out");

int main()
{
	int n,g,a,l,b;
	fin>>n>>g;
	l=(((n+1)*n)/2)*10;
	b=l-g;
	for(int i=0;i<n;i++)
	{
		fin>>a;
		if((n-a)==b)
		{
			fout<<i+1<<"\n";
			break;
		}
	}
	return 0;
}
