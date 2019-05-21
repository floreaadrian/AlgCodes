#include<fstream>
#include<string.h>

using namespace std;

ifstream fin("sumacifre.in");
ofstream fout("sumacifre.out");

int main()
{
	char c;
	int n,s=0,i;
	fin>>n;
	while(fin>>c)
	{
		if(c>='0' && c<='9')s=s+c-'0';
	}
	fout<<s;
	return 0;
}
