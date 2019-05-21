#include <fstream>
#include <vector>
#include <queue>
using namespace std;
int viz[100001],n,m,nodnr;
double long k,cost[100001];
vector <int> A[100001];
queue <int> q;
ifstream cin("date.in");
ofstream cout("date.out");

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
          nodnr++;
         }
 }
}

void goleste(int ma)
{
	for(int i=0;i<=ma;i++)
	{
		cost[ma]=0;
		viz[ma]=0;
	}
}
int main()
{int i;
	int nodes,a,b,cases=1;
	while(cin>>nodes && nodes){
		vector <int> A[10000];
		int ma=0;
		for(int i=0;i<nodes;i++)
		{
			cin>>a>>b;
			A[a].push_back(b);
			A[b].push_back(a);
			if(a>ma)
			ma=a;
			if(b>ma)
			ma=b;
		}
		int ttl,start;
		while(cin>>ttl && cin>>start && (start!=0 || ttl!=0)){
                goleste(ma);
                nodnr=0;
                bfs(start);
                int result = 0;
                 for(int j=1;j<=ma;j++){
                 	if(cost[j]>ttl)++result;
				 }
                 result += nodes-nodnr;
                 cout<<"Case "<<cases<<": "<<result<<" nodes not reachable from node "<<start<<" with TTL = "<<ttl<".\n";
                cases++;  
		}
	}
    
}
