#include<fstream>

using namespace std;

ifstream fin("bitona.in");
ofstream fout("bitona.out");

int main()
{
	int a,b,n,i,primul,seg,dir,udir;
	fin>>n>>a;
	primul=a;
	seg=udir=0;
	i=1;
	while(i<n && seg<4){
		fin>>b;
		dir=a<b ? 1: a>b ? -1:0;
		if(dir!=udir && dir!=0){
			seg++;
			udir=dir;
		}
		a=b;
		i++;
	}
	fin.close();
	if(seg==3){
		if((udir==1 && b>primul) || (udir=-1 && b<primul))
		seg=4;
	}
	if(seg<4)
	fout<<"DA\n";
	else
	fout<<"NU\n";
	fout.close();
	return 0;
}
