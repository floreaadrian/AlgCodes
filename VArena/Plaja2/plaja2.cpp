#include<fstream>

using namespace std;

ifstream fin("plaja2.in");
ofstream fout("plaja2.out");

int main()
{
	int r,bat,cmmdc,n,i,nr,nr1=1;
	fin>>n>>cmmdc;
	for(i=1;i<n;i++)
	{
	fin>>bat;
	while(bat>0) {
      r=cmmdc%bat;
      cmmdc=bat;
      bat=r;
    }
    }
	fout<<cmmdc;
	return 0;
}
