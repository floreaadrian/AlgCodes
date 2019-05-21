#include <fstream>
#include <vector>
using namespace std;

ifstream fin("examene.in");
ofstream fout("examene.out");

vector <int> G[305];
vector <int> Gt[305];
typedef vector <int> :: iterator It;

int n,m,p;
bool a[305][305],viz[405],inciclu[305];

void df(int nod)
{
	viz[nod]=1;
	for(It it=Gt[nod].begin(),fit=Gt[nod].end();it!=fit;it++)
	if(!viz[*it])
	df(*it);
}

void gciclu(){
	for(int k=1;k<=n;++k)
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	if(a[i][k] && a[k][j])
	a[i][j]=true;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	if(a[i][j] && a[j][i]){
	inciclu[i]=true;inciclu[j]=true;}
}

int main()
{
	fin>>n>>m>>p;
	for(int i=1;i<=m;i++){
		int x,y;
		fin>>x>>y;
		G[x].push_back(y);
		a[x][y]=1;
		Gt[y].push_back(x);
	}
	for(int i=1;i<=p;i++){
		int x;
		fin>>x;
		if(!viz[x])
		df(x);
	}
	gciclu();
	for(int i=1;i<=n;i++)
	if(!viz[i])
	fout<<i<<" ";
	fout<<"\n";
	for(int i=1;i<=n;i++)
	if(inciclu[i])
	fout<<i<<" ";
	fout<<"\n";
	return 0;
}
