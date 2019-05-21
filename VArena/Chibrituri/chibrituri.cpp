#include<fstream>

using namespace std;

ifstream fin("chibrituri.in");
ofstream fout("chibrituri.out");

int v[10]={4,2,2,2,3,2,3,2,4,3};
int o[10]={2,0,3,3,1,3,3,1,3,3};

int main()
{
	int nv,no,var,ora,min,omin,mmin,omax,mmax,c1,c2,c3,c4;
	fin>>nv>>no;
	fin.close();
	var=0;
	omin=-1;
	for(ora=0;ora<24;ora++)
	for(min=0;min<60;min++)
	{
		c1=ora/10;
		c2=ora%10;
		c3=min/10;
		c4=min%10;
		if(v[c1]+v[c2]+v[c3]+v[c4]==nv && o[c1]+o[c2]+o[c3]+o[c4]==no){
			var++;
			if(omin==-1){
				omin=ora;
				mmin=min;
			}
			omax=ora;
			mmax=min;
		}
	}
	fout<<var<<"\n";
	if(omin<10)fout<<0<<omin;else
	fout<<omin;
	if(mmin<10)fout<<":"<<0<<mmin;else
	fout<<":"<<mmin;
	fout<<"\n";
	if(omax<10)fout<<0<<omax;else
	fout<<omax;
	if(mmax<10)fout<<":0"<<mmax;else
	fout<<":"<<mmax;
	fout.close();
	return 0;
}
