#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int maxq(int a,int b){
    if(a>b)return a;
    return b;
}

int viz[100001],n,m,maxa=0;
double long k,cost[100001];
vector <int> A[100001],sa;
queue <int> q;

void bfs(int s)
{int i,nr_vecini,nod;
 q.push(s);
 viz[s]=1;
 while(!q.empty())
 {nod=q.front();
  q.pop();
  nr_vecini=A[nod].size();
  for(i=0;i<nr_vecini;i++)
      if(viz[A[nod][i]]==0)
         {q.push(A[nod][i]);
          viz[A[nod][i]]=1;
          cost[A[nod][i]]=cost[nod]+1;
          maxa=maxq(maxa,cost[A[nod][i]]);
         }
 }
}

void verf(){
    for(int i=1;i<=n;i++)
        if(cost[i]==maxa)
        sa.push_back(i);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<n;j++){
            A[i].push_back(j+1);
            A[j+1].push_back(i);
        }
    }
    int ans=0;
    bfs(1);
    for(int i=0;i<sa.size();i++){
        memset(cost,0,sizeof(cost));
        memset(viz,0,sizeof(viz));
        maxa=0;
        bfs(sa[i]);
        ans=maxq(maxa,ans);
    }
    cout<<ans;
    return 0;
}
