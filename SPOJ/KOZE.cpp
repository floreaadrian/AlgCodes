#include<iostream>
#include<vector>
#include<queue>
#include <string.h>
using namespace std;
int n,m,vis[255][255],f=0,fs=0,fw=0,k,v;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char a[255][255];
queue<int>x,y;
bool aiesit(int i,int j)
{
   if(i==0||i==n-1||j==0||j==m-1)
    return true;
   return false;
}
void bfs(int i,int j)
{
     x.push(i);
    y.push(j);
    int p,q;
    while(!x.empty())
    {
        p=x.front();
        q=y.front();
        x.pop();
        y.pop();
        if( vis[p][q]==1) continue;
        vis[p][q]=1;
        if(a[p][q]=='k')
            k++;
        else if(a[p][q]=='v')
            v++;
        if(aiesit(p,q))
            f=1;
        for(int h=0;h<4;h++)
        {
            int nx=dx[h]+p,ny=dy[h]+q;
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&a[nx][ny]!='#')
            {
                x.push(nx);
                y.push(ny);
            }
        }
    }
}
int main()
{
    int i,j;
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
          if(a[i][j]=='k'||a[i][j]=='v'&&vis[i][j]==0)
          {
              k=0;
              v=0;
              f=0;
              bfs(i,j);
              if(f==1)
              {
                  fs+=k;
                  fw+=v;
              }
              else if(k>v)
                fs+=k;
              else if(k<=v)
                fw+=v;
          }
    }
    cout<<fs<<" "<<fw;
    return 0;
}
