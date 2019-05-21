#include<fstream>

using namespace std;

ifstream fin("balaur.in");
ofstream fout("balaur.out");

int main()
{
	int a;
	fin>>a;
	fout<<a*5;
	return 0;
}
