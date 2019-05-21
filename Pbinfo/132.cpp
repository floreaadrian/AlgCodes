#include<fstream>
using namespace std;
ifstream fin("grade.in");
ofstream fout("grade.out");
int main()
{
	int ma[101][101],n,m,c;
	fin>>n;
	int x,y;
	while(fin>>x>>y){
		ma[x][y]=ma[y][x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		c=0;
	for(int j=1;j<=n;j++)
	if(ma[i][j]==1)c++;
	fout<<c<<" ";
	}
	return 0;
}
