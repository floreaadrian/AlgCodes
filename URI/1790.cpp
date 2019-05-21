#include <bits/stdc++.h>

using namespace std;

bitset <51> viz;
bool g[51][51];
int c,p;

void df(int node)
{
    viz[node]=true;
    for(int i=1;i<=c;++i)
        if(!viz[i] && g[i][node])
        df(i);
}

int main()
{
    while(scanf( "%d%d", &c, &p ) != EOF){
        int cnt=0;
        memset(g,false,sizeof(g));
        for(int i=0;i<p;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            g[x][y]=g[y][x]=true;
        }
        for(int i=1;i<=c;++i)
            for(int j=i+1;j<=c;++j)
                if(g[i][j]){
                    g[i][j]=g[j][i]=false;
                    viz.reset();
                    df(i);
                    for(int k=1;k<=c;k++)
                    if(!viz[k]){
                        cnt++;
                        break;
                    }
                    g[i][j]=true;
                }
        printf("%d\n",cnt);
    }
    return 0;
}
