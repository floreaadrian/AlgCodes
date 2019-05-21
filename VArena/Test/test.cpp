#include<fstream>

using namespace std;

ifstream fin("test.in");
ofstream fout("test.out");

int main()
{
	int a,b,d,cf,p10,max,maxprim,n1,n2,i;
	fin>>a>>b;
	n1=b;
	p10=1;
	while(n1>9)
	{
		p10*=10;
		n1/=10;
	}
	maxprim=1;
	max=a;
	n1=a;
	n2=b;
	a=a*10;
	while(a>0)
	{
		for(i=0;i<2;i++)
		{
		if(n1>max)
		max=n1;
		d=2;
		while((d*d>n1) && (n1%d>0))
		d++;
		if((d*d>n1) && (n1>maxprim))
        maxprim=n1;
        n1=n2;
		}
		a/=10;
		cf=a%10;
		n1=(b/10)*10+cf;
		n2=(cf*p10)+(b%p10);
	}
	if(maxprim>1)
	fout<<maxprim<<"\n";
	else
	fout<<max<<"\n";
	return 0;
}
