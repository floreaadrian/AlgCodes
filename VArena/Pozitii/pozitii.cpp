#include<fstream>

using namespace std;

ifstream fin("pozitii.in");
ofstream fout("pozitii.out");

int main()
{
	int a,n,i,c=0;
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>a;
		if(a==i)c++;
	}
	fout<<c;
	return 0;
}
