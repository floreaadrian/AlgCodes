#include<fstream>

using namespace std;

ifstream fin("tramvai.in");
ofstream fout("tramvai.out");

int r[10];

int main()
{
	int n,t,m,min,j,timp,i;
	fin>>n>>t;
	min=20000;
	for(i=0;i<n;i++)
	{
		fin>>m;
		for(j=0;j<m;j++)
		fin>>r[j];
		timp=0;
		j=0;
		while(timp<t){
			timp+=r[j];
			j=(j+1)%m;
		}
		if(timp-t<min)
		min=timp-t;
	}
	fin.close();
	fout<<min;
	fout.close();
	return 0;
}
