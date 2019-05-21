#include<fstream>

using namespace std;

ifstream fin("bete.in");
ofstream fout("bete.out");

int main()
{
	int n,a,b,maxa=0,maxb=0,cona=0,conb=0,i,sum1=0,re;
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>a;
		sum1+=a;
		if(a>maxa)
		{
			maxa=a;
			cona=1;
		}else
		if(a==maxa)cona++;
	}
	for(i=0;i<n;i++)
	{
		fin>>b;
		sum1+=b;
		if(b>maxb)
		{
			maxb=b;
			conb=1;
		}else
		if(b==maxb)conb++;
	}
	if(cona>conb)
	re=conb;
	else re=cona;
	fout<<sum1/n<<"\n"<<maxa+maxb<<"\n"<<re;
	return 0;
}
