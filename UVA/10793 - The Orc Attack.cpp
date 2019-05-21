#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_NODE 1001
#define INF 0x3f3f3f3f
using namespace std;
int d[MAX_NODE][MAX_NODE];
int nodes,edges;

void floyd(){
    for(int k=1;k<=nodes;k++)
        for(int i=1;i<=nodes;i++)
            for(int j=1;j<=nodes;j++){
                if(d[i][k]!=INF&&d[k][j]!=INF)d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
}

int main()
{
    int test,st, en, dist, w,cs=1;
    cin>>test;
    while(test--){
        cin>>nodes>>edges;
        memset(d,INF,sizeof(d));
        for(int i=1;i<=edges;i++){
            cin>>st>>en>>w;
            if(d[st][en]>w)d[st][en] = w;
            if(d[en][st]>w)d[en][st] = w;
        }
        for(int i=1;i<=nodes;i++)d[i][i]=0;
        floyd();
        dist = INF;
        int x;
        for(int i = 1; i <= nodes; i++ ){
            x = d[i][1];
            if(d[i][1] == x && d[i][2] == x && d[i][3] == x && d[i][4] == x && d[i][5]){
                int curdist = 0;
                for(int k = 1; k <= nodes; k++ )
                    curdist = max(curdist, d[i][k]);
                if(curdist < dist){
                    dist = curdist;
                }

            }
        }

        if(dist == INF) dist = -1;
        cout<<"Map "<<cs++<<": "<<dist<<"\n";
    }
  return 0;
}
