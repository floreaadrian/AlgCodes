#include<fstream>

using namespace std;

ifstream fin("concurs.in");
ofstream fout("concurs.out");

int main()
{
	int h,n,a,sh,oh,sh1=0,oh1=0;
	bool ok=false;
	fin>>h>>n;sh=(h/10)%10;oh=(h/100)%10;
	for(int i=1;i<=n;i++)
	{
		fin>>a;
		if(h==a)ok=true;
		if((a/100)%10==oh){
			oh1++;
			if((a/10)%10==sh)sh1++;
		}
	}
	if(ok)
	fout<<"DA\n";else
	fout<<"NU\n";
	fout<<oh1<<"\n";
	fout<<sh1<<"\n";
	return 0;
}
