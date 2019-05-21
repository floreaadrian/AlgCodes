#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;

int min1,N,from,start,sink,C[130][130];
bool viz[130];
vector <char> G[130];

void path(int x,int y){
    C[x][y]=C[x][y]-min1;
    C[y][x]=C[y][x]+min1;
}

int gaseste(int nod)
{
    if(viz[nod]==1){return 0;}
    viz[nod]=1;
    if(nod==sink){return 1;}
    int temp=min1;bool ch=false;
    for(int i=0;i<G[nod].size();++i){
        int to=G[nod][i];
        if(C[nod][to]!=0){
            min1=min(min1,C[nod][to]);
            ch=gaseste(to);
         if(ch==1){path(nod,to);return 1;}
	   min1=temp;
        }
    }
    return 0;
}

int solve()
{
    int ret=0;
    while(1)
    {
   memset(viz,false,sizeof(viz));
   min1=INF;
   if(!gaseste(start)){break;;}
    ret=ret+min1;
    }
    cout<<ret;
return 0;
}

int main()
{
    cin>>N;
    for(int i=1;i<=N;++i){
        char x,y;
        int c;
        cin>>x>>y>>c;
        if(x==y){continue;}
        G[x].push_back(y);
        G[y].push_back(x);
        C[x][y]=C[x][y]+c;
        C[y][x]=C[y][x]+c;
    }
    start='A';
    sink='Z';
    solve();
    return 0;
}
