#include <cstdio>

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n,m,t,x1,y1,x2,y2;
int v[55][55],d[55][55][150],div[150],exp[12001];
int x,y,p,u,i,j,e,k;

struct str{int x,y,d;} c[453750],aux;

inline bool ifinside(int x,int y){return x>0&&y>0&&x<=n&&y<=n;}
inline str mp(int x,int y,int d){str aux;aux.x=x;aux.y=y;aux.d=d;return aux;}

int cmmdc(int a, int b)
{
    if (a%b)
        return cmmdc(b,a%b);
    else
        return b;
}

int main()
{
    freopen("kdrum.in","r",stdin);
    freopen("kdrum.out","w",stdout);

    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            scanf("%d",&v[i][j]);

    for (e=1,k=0;e<=t;++e){
        if (t%e==0)
        {
            div[++k]=e;
            exp[e]=k;
        }
    }

    p=1;
    u=1;
    c[p].x=x1;
    c[p].y=y1;
    e=cmmdc(v[x1][y1],t);
    c[p].d=exp[t/e];
    d[x1][y1][exp[t/e]]=1;

    while (p<=u)
    {
        aux=c[p];
        for (i=0;i<4;++i)
        {
            x=aux.x+dx[i];
            y=aux.y+dy[i];
            if (ifinside(x,y)&&v[x][y])
            {
                e=div[aux.d]/cmmdc(v[x][y],div[aux.d]);
                if (d[x][y][exp[e]]>d[aux.x][aux.y][aux.d]+1||d[x][y][exp[e]]==0)
                {
                    d[x][y][exp[e]]=d[aux.x][aux.y][aux.d]+1;
                    ++u;
                    c[u]=mp(x,y,exp[e]);
                }
            }
        }
        ++p;
  }
  printf("%d",d[x2][y2][exp[1]]);
  return 0;
}
