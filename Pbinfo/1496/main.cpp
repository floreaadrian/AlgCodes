#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("harta1.in");
ofstream fout("harta1.out");

const int dx[]={-1,  0, 1, 0};
const int dy[]={ 0, -1, 0, 1};
int cl,n,m,a[105][105];

bool valid(int x,int y)
{
    return x<=n && x>=1 && y<=m && y>=1;
}

void fill(int x, int y, int s)
{
    if(a[x][y]==s)
    {
        cl++;
        a[x][y]=-a[x][y];
        for(int j=0;j<4;++j)
            {
                int xnou=x+dx[j];
                int ynou=y+dy[j];
                if(valid(xnou,ynou))
                    {
                        fill(xnou, ynou, s);
                    }
            }
    }
}

int main()
{
    int t,k;
    fin>>t;
    fin>>n>>m>>k;
    if(t==1){
        int kl,c=0;
        for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            fin>>kl;
            if(kl==0)
                c++;
        }
        fout<<c<<"\n";
    }else{
        int lm[11]={0},mm=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                fin>>a[i][j];
                a[i][j]=-a[i][j];
            }
        for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]<0)
            {
                cl=0;
                int act=a[i][j];
                fill(i,j,act);
                lm[-act]=max(lm[-act],cl);
                mm=max(cl,mm);
            }
        for(int i=1;i<=k;++i)
            if(lm[i]==mm)
                fout<<i<<" ";
    }
    return 0;
}
