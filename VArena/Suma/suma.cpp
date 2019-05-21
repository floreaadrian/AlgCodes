#include<fstream>

using namespace std;

ifstream fin("suma.in");
ofstream fout("suma.out");

int main()
{
	int i,n,n9;
	fin>>n;
	fin.close();
	n9=(n-1)/9;
	fout<<1;
	if(n>1){
		for(i=0;i<(n-2-n9);i++)
		fout<<0;
		fout<<(n-1)%9;
		for(i=0;i<n9;i++)
		fout<<9;
	}fout<<"\n";
	n9=n/9;
	for(i=0;i<n9;i++)
	fout<<9;
	fout<<n%9;
	for(i=0;i<(n-1-n9);i++)
	fout<<0;
	fout.close();
	return 0;
}
