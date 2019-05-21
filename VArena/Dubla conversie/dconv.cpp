#include<fstream>

#define MAXP2 (2 * 1048576LL * 1048576LL * 1048576LL)

using namespace std;

ifstream fin("dconv.in");
ofstream fout("dconv.out");

int main()
{
	int n;
	long long conv,p10,p2;
	fin>>n;
	fin.close();
	conv=0;
	p10=1;
	while(n>0){
		conv+=n%2*10;
		n/=2;
		p10*=10;
	}
	p2=MAXP2;
	while(p2>conv)
	p2/=2;
	while(p2>0){
		fout<<0+conv/p2;
		conv%=p2;
		p2/=2;
	}
	fout<<"\n";
	fout.close();
	return 0;
}
