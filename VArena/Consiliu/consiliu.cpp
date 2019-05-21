#include<fstream>

using namespace std;

ifstream fin("consiliu.in");
ofstream fout("consiliu.out");

int minute[1440];

int main()
{
	int n,i,hs,ms,ts,hf,mf,tf,nrmin;
	fin>>n;
	for(i=0;i<n;i++){
		fin>>hs>>ms>>hf>>mf;
		ts=hs*60+ms;
		tf=hf*60+mf;
		do{
			minute[ts]++;
			ts=(ts+1)%1440;
		}while(ts!=tf);
	}
	fin.close();
	nrmin=0;
	for(i=0;i<1440;i++)
	if(minute[i]==n)
	nrmin++;
	fout<<nrmin<<"\n";
	fout.close();
	return 0;
}
