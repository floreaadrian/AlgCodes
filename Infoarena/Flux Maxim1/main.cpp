#include <fstream>
#include <vector>
#include <queue>
#include <limits.h>
#define maxn 1001
using namespace std;
ifstream fin("maxflow.in");
ofstream fout("maxflow.out");
vector <int> G[maxn];
int C[maxn][maxn],P[maxn],F[maxn][maxn],N;
bool V[maxn];
bool Drum()
{
  for(int i=2;i<=N;i++)
    V[i]=false;
  queue <int> Q;
    Q.push(1);
  while(!Q.empty())
  {
    int nod=Q.front();
   if (nod==N){Q.pop();continue;}
    vector <int>::iterator i;
    for( i=G[nod].begin();i!=G[nod].end();i++)
      if(F[nod][*i]<C[nod][*i]&&!V[*i])
         {
           P[*i]=nod;
           Q.push(*i);
           V[*i]=true;
          }
     Q.pop();
    }
  return V[N];
}
int Flux ()
  {
      V[1]=true;
    P[1]=0;
    int flux_total=0;
    while(Drum())
           {
             int min1=INT_MAX;
              for(int x=N;x!=1;x=P[x])
                 if(C[P[x]] [x] - F[P[x]] [x]<min1)
                     min1=C[P[x]] [x] - F[P[x]] [x];
             flux_total+=min1;
             if (min1==0) continue;
           for(int x=N;x!=1;x=P[x])
            {
               F[P[x]][x]+=min1;
               F[x][P[x]]-=min1;
           }
         }
     return flux_total;
}
int main()
{
    int m;
    fin>>N>>m;
    for(int i=1;i<=m;++i){
        int x,y,z;
        fin>>x>>y>>z;
        G[x].push_back(y);
        G[y].push_back(x);
        C[x][y]=z;
    }
    fout<<Flux();
    return 0;
}
