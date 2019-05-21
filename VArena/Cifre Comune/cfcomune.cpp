#include<fstream>

using namespace std;

ifstream fin("cfcomune.in");
ofstream fout("cfcomune.out");

int fr[9];

int main()
{
	int i,a,b,c=0;
	fin>>a>>b;
	fin.close();
	while(a){
		fr[a%10]=1;
		a/=10;
	}
	while(b){
		if(fr[b%10]==1){
			fr[b%10]=0;
			c++;
		}
		b/=10;
	}
	fout<<c;
	fout.close();
	return 0;
}
