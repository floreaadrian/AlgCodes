#include<fstream>

using namespace std;

ifstream fin("vraji.in");
ofstream fout("vraji.out");

int main()
{
	int p,v,n,ob,cmmdc,max,r;
	fin>>n>>p>>v;
	max=p*v;
	cmmdc=max;
	for(int i=1;i<n;i++)
	{
		fin>>p>>v;
		ob=p*v;
		if(ob>max)
		max=ob;
		while(ob>0)
		{
			r=cmmdc%ob;
			cmmdc=ob;
			ob=r;
		}
	}
	fout<<max<<"\n"<<cmmdc;
	return 0;
}
