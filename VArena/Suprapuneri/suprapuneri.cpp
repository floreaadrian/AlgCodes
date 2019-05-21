#include<fstream>

#define P2MAX (1048576LL * 1048576 * 1048576 * 2)

using namespace std;

ifstream fin("suprapuneri.in");
ofstream fout("suprapuneri.out");

int main()
{
	long long m,n,p2,p2c;
	int supr;
	fin>>m>>n;
	fin.close();
	p2=P2MAX;
	while(p2>n && p2>m)
	p2/=2;
	if(p2==0)
	supr=1;
	else{
		 supr=0;
		 p2c=p2;
		 while(p2c>0){
		 	if(m==n)
			 supr++;
			m=m%p2*2+m/p2;
			p2c/=2;	
		 }
	}
	fout<<supr;
	fout.close();
	return 0;
}
