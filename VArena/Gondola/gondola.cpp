#include<fstream>

using namespace std;

ifstream fin("gondola.in");
ofstream fout("gondola.out");

int main()
{
	int n,h1,h2,d1,d2,maxd,maxdd,i,dd;
	long long s;
	fin>>n>>s;
	s++;
	fin>>h1;h1+=2;
	if(h1>s)
	d1=maxd=h1-s;
	else d1=maxd=s-h1;
	s+=h1;
	maxdd=0;
	for(i=2;i<n;i++)
	{
		fin>>h2;
		h2=h2+1+i%3;
		s+=h2;
		if(h2>h1)
		d2=h2-h1;
		else d2=h1-h2;
		if(d2>maxd)
		maxd=d2;
		if(d2>d1)
		dd=d2-d1;
		else dd=d1-d2;
		if(dd>maxdd)
		maxdd=dd;
		d1=d2;
		h1=h2;
	}
	fin.close();
	fout<<s<<"\n"<<maxd<<"\n"<<maxdd<<"\n";
	fout.close();
	return 0;
}
