#include<fstream>

using namespace std;

ifstream fin("fractie.in");
ofstream fout("fractie.out");

int main()
{
	int i,a,b,ac,bc,r,p2,p5,z;
	fin>>a>>b;
	fin.close();
	ac=a;
	bc=b;
	while(bc>0){
		r=ac%bc;
		ac=bc;
		bc=r;
	}
	a/=ac;
	b/=ac;
	fout<<a/b;
	if(a%b>0){
	fout<<".";
	a%=b;
	bc=b;
	p2=p5=0;
	while(bc%2==0){
		p2++;
		bc/=2;
	}
	while(bc%5==0){
		p5++;
		bc/=5;
	}
	z=p2>p5 ? p2:p5;
	for(i=0;i<z;i++){
		a*=10;
		fout<<a/b;
		a%=b;
	}
	if(a>0){
		fout<<"(";
		ac=a;
		do{
			a*=10;
			fout<<a/b;
			a%=b;
		}while(a!=ac);
		fout<<")";
	}
	}
	return 0;
}
