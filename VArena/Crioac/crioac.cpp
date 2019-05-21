#include<fstream>

using namespace std;

ifstream fin("crioac.in");
ofstream fout("crioac.out");

int main()
{
	int n,x,y,x1,y1,min,c1=0,c2=0,k;
	fin>>n>>x>>y;
	fin.close();
	min=n/x;
	fout<<min<<"\n";
	if((n+1)%(x+y)==0)
	{
		fout<<(n+1)/(x+y)*x;
	}else
	fout<<0;
	fout.close();
	return 0;
}
