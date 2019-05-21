#include<fstream>

using namespace std;

ifstream fin("cifre3.in");
ofstream fout("cifre3.out");

int va[9],vb[9];

int main()
{
	int a,b,nr=0,dif=0;
	fin>>a>>b;
	fin.close();
	while(a)
	{
		va[a%10]++;
		a/=10;
	}
	while(b)
	{
		vb[b%10]++;
		b/=10;
	}
	for(int i=0;i<10;i++)
	{
		if(va[i]!=0 && vb[i]==0)
		{
			dif=1;
			fout<<i<<" ";
		}
		if(va[9-i]>0 && vb[9-i]>0)
		{
			nr=nr*10+(9-i);
		}
	}
	if(dif!=1)
	fout<<-1<<"\n";
	else fout<<"\n";
	if(nr!=0)
	fout<<nr;
	else
	fout<<-1;
	fout.close();
	return 0;
}
