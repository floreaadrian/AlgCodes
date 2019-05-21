#include<fstream>
using namespace std;
ifstream fin("promote.in");
ofstream fout("promote.out");
int main()
{
	int br,sv,gl,pl,br1,sv1,gl1,pl1,cpl=0,csv=0,cgl=0;
	fin>>br>>br1>>sv>>sv1>>gl>>gl1>>pl>>pl1;
	if((pl1-pl)>0)
	{
		cpl+=(pl1-pl);
		csv+=(pl1-pl);
		cgl+=(pl1-pl);
	}
	if((gl1-gl)>0)
	{
		csv+=(gl1-gl);
		cgl+=(gl1-gl);
	}
	if((sv1-sv)>0)
	csv+=(sv1-sv);
	fout<<csv<<"\n"<<cgl<<"\n"<<cpl;
	return 0;
}
