#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
typedef pair <int , int > pii;

#define INF (1000000000)
#define ull unsigned long long

int O,m,n;
int dr[]={0,0,-1,1,1,1,-1,-1};
int dc[]={1,-1,0,0,1,-1,1,-1};
bool inRange(int a,int b){ return a>=0 && a<m && b>=0 && b<n;}


char arr[101][101];
map <pii,int > dist;


int bfs(int a,int b)
{
    queue <pii> q;
    dist[pii(a,b)]=0;
    q.push(pii(a,b));
    while(!q.empty())
    {
        pii front=q.front();q.pop();
        a=front.first;b=front.second;
        for(int i=0;i<8;i++)
        {
            int x=a+dr[i],y=b+dc[i];

            if(inRange(x,y) && arr[x][y]!='#' && dist[pii(x,y)]==INF)
            {
                dist[pii(x,y)]=dist[pii(a,b)]+1;
                q.push(pii(x,y));
            }
            if(inRange(x,y) && arr[x][y]=='T')
            {
                dist[pii(x,y)]=dist[pii(a,b)]+1;
                return dist[pii(x,y)];
            }
        }
    }
    return INF;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int Sx=-1,Sy=-1,Tx=-1,Ty=-1;
        cin>>O>>m>>n;
        char ch;
        cin>>ch;
        dist.clear();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>ch;
                arr[i][j]=ch;
                dist[pii(i,j)]=INF;
                if(arr[i][j]=='S')
                    Sx=i,Sy=j;
                if(arr[i][j]=='T')
                    Tx=i,Ty=j;
            }
           cin>>ch;
        }


        if(Sx==-1 || Sy==-1 || Tx==-1 || Ty==-1)
        {
            cout<<"Impossible\n";
            continue;
        }
        int val=bfs(Sx,Sy);
        if(val <= O)
            cout<<"Possible\n";
        else
             cout<<"Impossible\n";
    }
    return 0;
}
