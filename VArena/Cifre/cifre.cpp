#include<fstream>

using namespace std;

ifstream fin("cifre.in");
ofstream fout("cifre.out");

int main()
{
	int cf1,cf2,aux,n;
	for(int i=0;i<3;i++)
	{
	fin>>n;
	cf1=(n/10)%10;
	cf2=n%10;
	if(cf1==cf2)
	fout<<"0 ";else
	{
		while(n>0 && n%10==cf2)
		{
			n/=10;
			aux=cf1;
			cf1=cf2;
			cf2=aux;
		}
		if(n==0)
		fout<<"1 ";
		else
		fout<<"0 ";
	}
    }
    return 0;
}
