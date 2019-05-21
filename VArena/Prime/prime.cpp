#include<fstream>

using namespace std;

ifstream fin("prime.in");
ofstream fout("prime.out");

char ciur[3000001];

int main()
{
	int x,n,i,d,nou;
	long long suma;
	fin>>x>>n;
	for(d=2;d*d<=3000000;d++)
	  if(ciur[d]==0)
		for(i=d*d;i<=3000000;i=i+d)
		  ciur[i]=1;
	nou=x;
	while(ciur[nou]==1)
	nou--;
	fout<<nou<<"\n";
	suma=0;
	for(i=0;i<n;i++)
	{
		x++;
		while(ciur[x]==1)
		x++;
		suma+=x;
	}
	fout<<suma;
	return 0;
}
