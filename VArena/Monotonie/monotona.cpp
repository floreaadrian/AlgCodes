#include<fstream>

using namespace std;

ifstream fin("monotona.in");
ofstream fout("monotona.out");

int main()
{
	int n,i,a,b,dir;
	fin>>n;
	fin>>a;
	dir=0;
    i=1;
    while(i<n&&dir<2) {
    fin>>b;
    if (b>a) // secventa devine crescatoare, daca se mai poate
      if (dir<0)
        dir=2;
      else
        dir=1;
    else if (b<a) // secventa devine descrescatoare, daca se mai poate
      if (dir>0)
        dir=2;
      else
        dir=-1;
    a=b;
    i++;
  }
  if(dir<2)
  fout<<"da";else
  fout<<"nu";
	return 0;
}
