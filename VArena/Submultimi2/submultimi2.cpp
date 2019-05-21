#include<fstream>

#define mo 982451653

using namespace std;

ifstream fin("submultimi2.in");
ofstream fout("submultimi2.out");

int main()
{
	int n,ns,i,c,cc,s;
	long long nasoc,pn;
	fin>>n;
	fin.close();
	ns=1;
	for(c=0;c<n;c++)
	ns*=2;
	s=0;
	for(c=2;c<ns;c++){
		cc=c;
		pn=1;
		nasoc=0;
		i=0;
		while(cc>0){
			if(cc%2==1){
				nasoc=(nasoc+i*pn)%mo;
				pn=(pn*n)%mo;
			}
			cc/=2;
			i++;
		}
		s=(s+nasoc)%mo;
	}
	fout<<s;
	fout.close();
	return 0;
}
