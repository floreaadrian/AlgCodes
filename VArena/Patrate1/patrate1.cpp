#include<fstream>

using namespace std;

ifstream fin("patrate1.in");
ofstream fout("patrate1.out");

int a[200][200];

int main()
{
	int n,l,c,lin,col,maxlat,nrpat,lat;
	fin>>n;
	for(l=0;l<n;l++){
	for(c=0;c<n;c++)
	fin>>a[l][c];
	}
	nrpat=0;
	for(lin=0;lin<n;lin++)
	for(col=0;col<n;col++){
		maxlat=n-lin;
		if(n-col<maxlat)
		maxlat=n-col;
		lat=1;
		l=0;
		while(lat<=maxlat && l==lat-1){
			l=c=0;
			while(c<lat && a[lin+lat-1][col+c]==1)
			c++;
			if(c==lat)
			while(l<lat && a[lin+l][col+lat-1]==1)
			l++;
			if(l==lat)
			nrpat++;
			lat++;
		}
	}
	fout<<nrpat;
	return 0;
}
