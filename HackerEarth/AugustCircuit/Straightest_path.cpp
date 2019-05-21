#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};

int a[1005][1005]={0};

bool inside(int x,int y,int n,int m)
{
    return x>=1 && x<=n && y>=1 && y<=m;
}

int lee(int n,int m,int sti,int stj,int fini,int finj)
{
    int status=0;
    queue <pair<int,int> > q;
    q.push(make_pair(sti,stj));
    int c=0;
    a[sti][stj]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==fini && y==finj) return a[x][y]-1;
        for(int dir=0;dir<4;++dir){
            int xu=x+di[dir];
            int yu=y+dj[dir];
            if(inside(xu,yu,n,m) && a[xu][yu]!=-1)
            {
                if(dir!=status){
                    if(a[xu][yu]==0 || a[xu][yu] > a[x][y] + 1){
                    status=dir;
                    a[xu][yu]=a[x][y]+1;
                    q.push(make_pair(xu,yu));
                    }
                }else {
                    a[xu][yu]=a[x][y];
                    q.push(make_pair(xu,yu));
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n,m,sti,stj,fini,finj;
    string s;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        for(int j=0;j<m;++j)
        if(s[j]=='V') {
            sti=i;
            stj=j+1;
        }
        else if(s[j]=='H') {
            fini=i;
            finj=j+1;
        }
        else if(s[j]=='*') a[i][j+1]=-1;
    }
    printf("%d\n",lee(n,m,sti,stj,fini,finj));
    return 0;
}
