#include<fstream>

using namespace std;

ifstream fin("minnr.in");
ofstream fout("minnr.out");

int fr[9];

int main()
{
	int n,a,i,j,cf;
	fin>>n;
	fin.close();
	while(n)
	{
		fr[n%10]++;
		n/=10;
	}
	cf=1;
	while(fr[cf]==0)
	cf++;
	fout<<cf;
	fr[cf]--;
	for(i=0;i<=9;i++)
	{
		if(fr[i]){
			while(fr[i]--)
			fout<<i;
		}
	}
	fout.close();
	return 0;
}
