#include<fstream>

using namespace std;

ifstream fin("joc3.in");
ofstream fout("joc3.out");

int bo[40000],ro[40000];

int main()
{
	int b,r,sar,n,y,x,gat,co,i;
	fin>>n>>x>>y;
	b=r=0;
	bo[b]=ro[r]=1;
	sar=0;
	gat=0;
	while(!gat){
		b=(b+x)%n;
		r=(r-y+n)%n;
		sar++;
		if(bo[b]==1 || ro[r]==1 || b==r)
		gat=1;
		bo[b]=1;
		ro[r]=1;
	}
	co=0;
	for(i=0;i<n;i++)
	if(bo[i]==0 && ro[i]==0)
	co++;
	fout<<co<<" "<<sar<<" "<<b+1<<" "<<r+1;
	return 0;
}
