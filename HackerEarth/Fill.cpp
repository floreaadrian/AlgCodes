#include <iostream>
#include <stdio.h>

using namespace std;

bool viz[11][11];
int ma[11][11],n,m;

bool dfs(int x,int y)
{
    if(x==n && y==m)
        return true;
    if(x>n || y>m)
        return false;
    if(x<0 || y<0)
        return false;
    if(viz[x][y])
        return false;
    if(!ma[x][y])
        return false;
    viz[x][y]=true;
    if(dfs(x+1,y)) return true;
    if(dfs(x-1,y)) return true;
    if(dfs(x,y+1)) return true;
    if(dfs(x,y-1)) return true;
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&ma[i][j]);
    /*for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            printf("%d ",ma[i][j]);
        printf("\n");
    }*/
    if(dfs(1,1))printf("Yes");
    else printf("No");
    return 0;
}
