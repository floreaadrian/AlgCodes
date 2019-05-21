#include<fstream>
#include<string.h>
//#include <stdio.h>

using namespace std;

ifstream fin("alfanumeric.in");
ofstream fout("alfanumeric.out");

int main()
{
	FILE *fin, *fout;
	char c;
	int n,s=0,i;
	fin>>n;
	for(i=0;i<n;i++)
	{
		c=fgetc(fin);
		if(c>='0' && c<='9')s=s+c-'0';
		else
		if(c>='a' && c<='z'){
			c='A'+c-'a';fout<<c;
		}
		else
		if(c>='A' && c<='Z')fout<<c;
	}
	fout<<"\n";
	fout<<s;
	return 0;
}
