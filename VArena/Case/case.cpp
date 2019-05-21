#include<fstream>

using namespace std;

ifstream fin("case.in");
ofstream fout("case.out");

int r1,r2,r3,b,f,c;

int main()
{
	int n,i,a,c1;
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>a;
		c1=a/1000;
		if(c1==1)r1++;
		if(c1==2)r2++;
		if(c1==3)r3++;
		c1=(a/100)%10;
		b+=c1;
		c1=(a/10)%10;
		f+=c1;
		c1=a%10;
		c+=c1;
	}
	fout<<r1<<"\n"<<r2<<"\n"<<r3<<"\n"<<b<<"\n"<<f<<"\n"<<c<<"\n";
	return 0;
}
