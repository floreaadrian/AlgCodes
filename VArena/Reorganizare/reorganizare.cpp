#include<fstream>

using namespace std;

ifstream fin("reorganizare.in");
ofstream fout("reorganizare.out");

int main()
{
	int n,k,i,nr,nrc,p10,cifra;
	fin>>n;
	fin.close();
	k=n*(n-1)/2;
	nr=nrc=1;
	p10=1;
	for(i=1;i<=k+n;i++){
		if(p10==0){
			nrc++;
			nr=nrc;
			p10=1000000;
			while(p10>nr)
			p10/=10;
		}
		cifra=nr/p10;
		nr=nr%10;
		p10/=10;
		if(i==k+1 || i==k+n)
		fout<<cifra<<" ";
	}
	fout.close();
	return 0;
}
