#include<fstream>

using namespace std;

ifstream fin("pinochio.in");
ofstream fout("pinochio.out");

int main()
{
	int n,p,k,l,m;
	fin>>n>>p>>k;
	if(k<=5){
		n+=(k*p);fout<<n;
		return 0;
	}
	if(k==6){
		n--;n+=(5*p);fout<<n;
		return 0;
	}if(k==7){
		n-=2;n+=(5*p);fout<<n;
		return 0;
	}
	l=k/7;
	m=k%7;
	if(m==6)
	{
		n=n+(l*5*p)+(m*p)-(l*2);
		n-=p+1;
		fout<<n;return 0;
	}
	n=n+(l*5*p)+(m*p)-(l*2);
	fout<<n;
	return 0;
}
