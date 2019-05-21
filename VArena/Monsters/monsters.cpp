#include<fstream>

using namespace std;

ifstream fin("monsters.in");
ofstream fout("monsters.out");

int main()
{
	int n,p2,cf;
	long long c;
	fin>>c;
	fin.close();
	n=0;
	p2=1;
	while(c>0){
		if(c%10>0)
		n+=p2;
		p2*=2;
		c/=10;
	}
	fout<<n;
	fout.close();
	return 0;	
}
