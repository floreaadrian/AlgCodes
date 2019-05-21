#include<fstream>
#include<cstdlib>
#define MAXV 103
#define MAXN 5001
#define min(x,y) ((x)<(y)?(x):(y))
#define abs(x) ((x)>0?x:-x)
using namespace std;

ifstream fin("ghizi.in");
ofstream fout("ghizi.out");

int n,k,s,d,viz[MAXV],Q[MAXV];
int *C[MAXV];
int *F[MAXV];
struct arc{
	int x,y,uz;
} G[MAXN];

void citire(void);
void afisare(void);
void ek(void);
int bfs(void);

int main()
{
	citire();
	ek();
	afisare();
	return 0;
}

void citire()
{
	int i,t1,t2;
	for(i=0;i<MAXV;i++){
		C[i]=(int *) calloc(MAXV,sizeof(int));
		F[i]=(int *) calloc(MAXV,sizeof(int));
	}
	fin>>n>>k;
	for(i=1;i<=n;i++)
	{
		fin>>t1>>t2;
		C[t1+1][t2+1]++;
		G[i].x=t1+1;G[i].y=t2+1;
	}
	C[MAXV-1][1]=k;
	s=MAXV-1; d=MAXV-2;
}

void afisare()
{
	int i,j,p,nr=0;
	for(i=1;i<MAXV-1;i++)
	for(j=1;j<MAXV-1;j++)
	if(F[i][j]){
		p=0;
		while(p<n && !(G[p+1].x==i && G[p+1].y==j && G[p+1].uz==0))
		p++;
		if(p<n){
			G[p+1].uz=1;nr++;
		}
	}
	fout<<nr<<"\n";
	for(i=1;i<=n;i++)
	if(G[i].uz) fout<<i<<" ";
}

void ek()
{
	int i,a,b,lg,v;
	int L[MAXV];
	do{
		for(i=1;i<MAXV;i++)viz[i]=0;
		if(bfs()) return;
		L[0]=d;lg=0;
		a=10000;
		while(L[lg]!=s){
			L[++lg]=abs(viz[L[lg-1]]);
			if(viz[L[lg]>0])
			a=min(a,C[L[lg]][L[lg-1]]-F[L[lg]][L[lg-1]]);
		}
		for(i=lg;i>0;i--) F[L[i]][L[i-1]]+=a;
	}while(1);
}

int bfs()
{
	int p,u,i,x;
	Q[0]=s;p=u=0;viz[s]=1;
	while(p<=u && !viz[d])
	{
		x=Q[p++];
		for(i=1;i<MAXV;i++)
		if(!viz[i])
		if(F[x][i]<C[x][i])
		{
			viz[i]=x;Q[++u]=i;
		}
	}
	return !viz[d];
}
