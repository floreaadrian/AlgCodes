#include<fstream>

using namespace std;

ifstream fin("bancomat.in");
ofstream fout("bancomat.out");

int main()
{
	int s,a,n,i,cf;
	fin>>s>>n;
	for(i=0;i<n;i++){
		fin>>a;
		cf=a%10;
		a/=10;
		if(cf==2)s+=a;
		else{
			if(s>=a)
			s-=a;
		}
	}
	fin.close();
	fout<<s;
	fout.close();
	return 0;
}
