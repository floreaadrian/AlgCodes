#include<fstream>
using namespace std;

ifstream fin("tsunami.in");
ofstream fout("tsunami.out");

int n,m,h,a[1000][1000];

int dx={0,0,1,-1};
int dy={1,-1,0,0};

void citire()
{
	fin>>n>>m>>h;
	for(int i=1;i<=n;++i)
	for(int j=1;i<=n;++j)
	fin>>a[i][j];
}
void fill()
{
	int xnou , ynou 
}

int main()
{
	citire();
	
}
