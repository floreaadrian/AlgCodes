#include<fstream>

using namespace std;

ifstream fin("medalion.in");
ofstream fout("medalion.out");

int a[301][301];
int dlin[4]={1,0,-1,0};
int dcol[4]={0,-1,0,1};

int main()
{
	int k,n,p,l,i,c,contor,sum,maxsum,e,len,dir;
	fin>>k>>n>>p;
	contor=1;
	l=c=n/2;
	a[l][c]=1;
	for(len=2;len<n;len+=2){
		l--;
		c++;
		for(dir=0;dir<4;dir++)
		for(i=0;i<len;i++){
			l+=dlin[dir];
			c+=dcol[dir];
			contor++;
			if(contor>k)
			contor=1;
			a[l][c]=contor;
		}
	}
	maxsum=0;
	for(l=0;l<n;l++){
		sum=0;
		for(c=0;c<n;c++)
		sum+=a[l][c];
		if(sum>maxsum)
		maxsum=sum;
	}
	e=1+((2*p+1)%k*(2*p+1)%k-p%k-1+k)%k;
	fout<<maxsum<<"\n"<<e;
	return 0;
}
