#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int viz[100001],n,m,s,cost[100001];
vector <int> A[100001];
queue <int> q;

void citire_graf()
{
    int x,y,i;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        A[x].push_back(y);
        A[y].push_back(x);
    }
    cin>>s;
}

void bfs()
{
    int i,nr_vecini,nod;
    q.push(s);
    viz[s]=1;
    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        nr_vecini=A[nod].size();
        for(i=0;i<nr_vecini;i++)
        if(viz[A[nod][i]]==0)
         {
             q.push(A[nod][i]);
            viz[A[nod][i]]=1;
            cost[A[nod][i]]=cost[nod]+6;
         }
    }
}

int main()
{
    int i,t;
    cin>>t;
    while(t--){
    citire_graf();
    bfs();
    for(i=1;i<=n;i++)
        if(cost[i]!=0 && i!=s) cout<<cost[i]<<" ";
        else if(cost[i]==0 && i!=s)
            cout<<-1<<" ";
        cout<<"\n";
        memset(cost,0,sizeof(cost));
        memset(A,0,sizeof(A));
        memset(viz,0,sizeof(viz));
    }
    return 0;
}
