#include<fstream>

using namespace std;

ifstream fin("decbin.in");
ofstream fout("decbin.out");

int main()
{
	int n,b,c,cc;
	long long cb,pb;
	fin>>n>>b;
	fin.close();
	c=cb=0;
	while(cb<=n){
		fout<<cb<<"\n";
		c++;
		cc=c;
		pb=1;
		cb=0;
		while(cc>0){
			cb+=pb*(cc%2);
			pb*=b;
			cc/=2;
		}
	}
	fout.close();
	return 0;
}
