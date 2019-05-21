#include<fstream>

using namespace std;

ifstream fin("cifre4.in");
ofstream fout("cifre4.out");

int fr[10];

int main()
{
	int a,s=0,i,n,max,nr,cs=0;
	fin>>n;
	fin.close();
	max=(((n/10)%10)*10)+n%10;
	a=n;
	while(n)
	{
		fr[n%10]++;
		n/=10;
		nr=(((n/10)%10)*10)+n%10;
		if(nr>max)
		max=nr;
	}
	for(i=9;i>=0;i--)
	{
		if(fr[i] && i>cs)cs=i;
		s=fr[0]+fr[4]+fr[1]+fr[9]; 
	}
	fout<<cs<<"\n"<<s<<"\n"<<max<<"\n";
	fout.close();
	return 0;
}
