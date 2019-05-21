#include<fstream>
#include<bitset>
using namespace std;

ifstream fin("ciur.in");
ofstream fout("ciur.out");

bitset <2000001> ciur;

int main()
{
	int n,c=0,i,d;
	fin>>n;
	for(d=2;d*d<=n;d++)
	  if(ciur[d]==0)
		for(i=d*d;i<=n;i=i+d)
		  ciur[i]=1;
	for(i=2;i<=n;i++)
	if(!ciur[i])
	c++;
	fout<<c;
	return 0;
}
