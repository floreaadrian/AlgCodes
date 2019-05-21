#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

char grid [1010][1010];
int vis [1001][1001];

int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,1,0,-1,1,-1,1,-1};

int n, m;

int inside_grid(int x, int y){
    return x>=0&&y>=0&&x<n&&y<m;
}

int bfs(int sx, int sy, int fx, int fy){
    memset(vis,-1,sizeof vis);
    queue<pair<int, pair<int, int> >> q;
    q.push(make_pair(sx,make_pair(sy,0)));
    vis[sx][sy] = 0;
    while(!q.empty()){
        pair<int, pair<int, int> > p = q.front();
        q.pop();
        if (p.first==fx&&p.second.first==fy)
            return p.second.second;
        if (p.second.second>vis[p.first][p.second.first]||grid[p.first][p.second.first]=='X'||vis[p.first][p.second.first]==-1)
            continue;
        for (int i=0;i<8;i++){
            int j =1,nx,ny;
            while(1){
                nx = p.first+dx[i]*j;
                ny = p.second.first+dy[i]*j;
                if (inside_grid(nx,ny)&&grid[nx][ny]!='X'){
                    if ((vis[nx][ny]==-1||vis[nx][ny]>p.second.second+1)){
                        q.push(make_pair(nx, make_pair(ny,p.second.second+1)));
                        vis[nx][ny] = p.second.second+1;
                    }
                }
                else break;
                j++;
            }
        }
    }
    return -1;
}

int main(){
    int t,sx,sy,fx,fy;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
            scanf("%s",grid[i]);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (grid[i][j]=='S'){
                    sx = i;sy=j;
                }
                else if (grid[i][j]=='F'){
                    fx = i;fy=j;
                }
        printf("%d\n", bfs(sx,sy,fx,fy));
    }
}
