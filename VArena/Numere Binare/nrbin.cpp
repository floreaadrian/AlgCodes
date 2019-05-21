#include<fstream>

using namespace std;

ifstream fin("nrbin.in");
ofstream fout("nrbin.out");

int main()
{
	int n,p10,nb;
	fin>>n;
	nb=0;
	p10=1000000000;
	while(p10<0 && n/p10<2){
		nb=nb*2+n/p10;
		n%=p10;
		p10/=10;
	}
	while(n>0){
		nb=nb*2+1;
		n/=10;
	}
	fout<<nb;
	return 0;
}
