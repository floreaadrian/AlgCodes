#include <fstream>
#include <string.h>
using namespace std;
ifstream cin("insule.in");
ofstream cout("insule.out");
const int dx[]={-1,  0, 1, 0};
const int dy[]={ 0, -1, 0, 1};
int a[105][105], l[105][105], minim=((1<<31)-1), u, p, nr, ng, nb, q[3][10005], k, xnou, ynou, n, m;
void read()
{
    char c;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            {
                cin.get(c);
                if(c=='\n') cin.get(c);
                if(c=='0')
                    a[i][j]=0;
                else if(c=='1')
                    {
                        a[i][j]=-1;
                        q[1][++k]=i;
                        q[2][k]=j;
                    }
                else if(c=='2')
                    a[i][j]=-2;
                else a[i][j]=-3;
            }
}
void intr(int c, int d)
{
    u=u+1;
    if(u>10000)
        u=1;
    q[1][u]=c;
    q[2][u]=d;
}
void extr(int &c, int &d)
{
    p=p+1;
    if(p>10000)
        p=1;
    c=q[1][p];
    d=q[2][p];
}
void fill(int x, int y, int s)
{
    if(a[x][y]==s)
    {
        a[x][y]=-a[x][y];
        for(int j=0;j<4;++j)
            {
                xnou=x+dx[j];
                ynou=y+dy[j];
                if(xnou>=1 && xnou<=n && ynou>=1 && ynou<=m)
                    fill(xnou, ynou, s);
            }
    }
}
void lee()
{
    int x, y;
    u=k;
    p=0;
    while(p<=u)
    {
        extr(x, y);
        for(int i=0;i<4;++i)
        {
            xnou=x+dx[i];
            ynou=y+dy[i];
            if(xnou>=1 && xnou<=n && ynou>=1 && ynou<=m)
                {
                    if(a[xnou][ynou]==0)
                    {
                        if(l[xnou][ynou]==0)
                            {
                                l[xnou][ynou]=l[x][y]+1;
                                intr(xnou, ynou);
                            }
                    }
                    else if(a[xnou][ynou]==2)
                    {
                        if(minim>l[x][y]
                            && l[x][y])
                            minim=l[x][y];
                    }
                }
        }
    }
}
void solve()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==-1)
                    nr++, fill(i, j, -1);
            else if(a[i][j]==-2)
                    ng++, fill(i, j, -2);
            else if(a[i][j]==-3) nb++, fill(i, j, -3);
    lee();
}
void print()
{
    cout<<nr<<" "<<ng<<" "<<nb<<" "<<minim<<"\n";
}
int main()
{
    read();
    solve();
    print();
    cin.close();
    cout.close();
    return 0;
}
