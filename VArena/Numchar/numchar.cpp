#include<fstream>
#include<string.h>

using namespace std;

ifstream fin("numchar.in");
ofstream fout("numchar.out");

char c;

int main()
{
	int n,i,cf=0,li=0;
	fin>>n;
	while(fin>>c)
	{
		if(c>='0' && c<='9')cf++;
		else
		if((c>='A' && c<='Z') || (c>='a' && c<='z'))li++;
	}
	fout<<li<<" "<<cf;
	return 0;
}
