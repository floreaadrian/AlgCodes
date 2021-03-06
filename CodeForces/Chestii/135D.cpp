#include <iostream>
#include <cstdio>
using namespace std;

int du[1005][1005],hash[1005][1005],d[1000005][2],l[8][2]={{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
char map[1005][1005];
int flag=0,o,n,m;

bool dfs(int x,int y)
{
   bool f=1;
   hash[x][y]=flag;
   if (map[x][y]=='1')
   {
      d[++o][0]=x;
      d[o][1]=y;
   }
   else
      for (int i=0;i<8;i++)
      {
         int dx=x+l[i][0],dy=y+l[i][1];
         if (dx<=0||dy<=0||dx>n||dy>m||hash[dx][dy]!=flag&&!dfs(dx,dy))
            f=0;
      }
   return f;
}

int dfs2(int x,int y)
{
   int s=1;
   hash[x][y]=0;
   for (int i=0;i<4;i++)
   {
      int dx=x+l[i][0],dy=y+l[i][1];
      if (dx>0&&dy>0&&dx<=n&&dy<=m&&hash[dx][dy]==flag&&map[dx][dy]=='1')
         s+=dfs2(dx,dy);
   }
   return s;
}

int main()
{
   int ans=0;
   cin>>n>>m;
   for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
   cin>>map[i][j];
   for (int i=1;i<n;i++)
      for (int j=1;j<m;j++)
         if (map[i][j]=='1'&&map[i][j+1]=='1'&&map[i+1][j]=='1'&&map[i+1][j+1]=='1')
            ans=4;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         if (map[i][j]=='0'&&!hash[i][j])
         {
            o=0;
            flag++;
            if (dfs(i,j)&&dfs2(d[1][0],d[1][1])==o)
            {
               for (int k=1;k<=o;k++)
                  du[d[k][0]][d[k][1]]=0;
               for (int k=1;k<=o;k++)
                  for (int a=0;a<4;a++)
                  {
                     int x=d[k][0]+l[a][0],y=d[k][1]+l[a][1];
                     du[x][y]++;
                  }
               for (int k=1;k<=o;k++)
                  if (du[d[k][0]][d[k][1]]!=2)
                     goto out;
               ans=max(ans,o);
               out:; 
            }
         }
   cout<<ans<<endl;
   return 0;
}
