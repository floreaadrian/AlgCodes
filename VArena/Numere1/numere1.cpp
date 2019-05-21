#include<fstream>

using namespace std;

ifstream fin("numere1.in");
ofstream fout("numere1.out");

int main()
{
	int n,i,nr,nap,d;
	nap=0;
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>nr;
		d=2;
		while(d*d<nr && nr%d>0)
		d++;
		if(d*d<nr){
			nr/=d;
			if(nr%d>0)
			{
				while(d*d<nr && nr%d>0)
				d++;
				if(d*d>nr)
				nap++;
		}
		}
	}
	fout<<nap;
	fin.close();
	fout.close();
	return 0;
}
