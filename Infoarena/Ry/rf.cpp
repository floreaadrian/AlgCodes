#include<fstream>
using namespace std;

ifstream fin("rf.in");
ofstream fout("rf.out");

int n,r[260][260],a[260][260];

void citire(){
	fin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		fin>>a[i][j];
		if(i!=j)
		r[i][j]=1;
	}
	fin.close();
}

void rf()
{
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if((a[i][j]>a[i][k]+a[k][j]) && (i!=j)){
			a[i][j]=a[i][k]+a[k][j];
			r[i][j]=r[i][k]+r[k][j];
		}else if((a[i][j]==a[i][k]+a[k][j]) && (i!=j))
		if(r[i][j]<r[i][k]+r[k][j])
		r[i][j]=r[i][k]+r[k][j];
	}
}

void write()
{
    for(int i=1;i<=n;++i, fout<<"\n")
        for(int j=1;j<=n;++j, fout<<" ")
            fout<<a[i][j];
    for(int i=1;i<=n;++i, fout<<"\n")
        for(int j=1;j<=n;++j, fout<<" ")
            fout<<r[i][j];
    fout.close();
}

int main()
{
	citire();
	rf();
	write();
	return 0;
}
