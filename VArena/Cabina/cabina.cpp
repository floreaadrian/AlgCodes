#include<fstream>

using namespace std;

ifstream fin("cabina.in");
ofstream fout("cabina.out");

int main()
{
	int n,a1,a2,a3,b,nro,l,spec=0;
	fin>>n;
	fin>>a1>>nro;
	fin>>a2>>b;
	nro+=b;
	if(a2>a1)
	l=3*(a2-a1);
	else
	l=a1-a2;
	for(int i=2;i<n;i++)
	{
		fin>>a3>>b;
		nro+=b;
		if(a3>a2)
		l+=(3*(a3-a2));
		else
		l+=a2-a3;
		if((a1<a2&&a2>a3) || (a1>a2&&a2<a3))
		spec++;
		a1=a2;
		a2=a3;
	}
	fout<<nro<<"\n"<<l<<"\n"<<spec<<"\n";
	return 0;
}
