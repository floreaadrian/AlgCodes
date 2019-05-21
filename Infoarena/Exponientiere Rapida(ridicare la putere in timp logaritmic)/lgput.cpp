#include<fstream>

using namespace std;

ifstream fin("lgput.in");
ofstream fout("lgput.out");

int main()
{
	long long a,n;
	fin>>a>>n;
	long long p=1;
	while(n>0){
		if(n%2==1)
		p*=a;
		a=a*a;
		n/=2;
	}
	fout<<p;
	return 0;
}
