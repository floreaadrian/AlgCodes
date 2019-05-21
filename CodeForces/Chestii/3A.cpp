#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#include <map>
using namespace std;

int mX[8]= {-1,-1,0,1,1,1, 0,-1};
int mY[8]= {0,1,1,1,0,-1,-1,-1};
string moves[8] = {"D","RD","R","RU","U","LU","L","LD"};
string path[66];

int visited[9][9]={0};
map<int,int> route;

bool validPosition(int a, int b){
    return ((a<9 && a>0) && (b<9 && b>0))?true:false;
}

int bfs(int a1,int a2, int b1, int b2) {
    queue<pair <int,int> > s;
    pair <int,int> start (a1,a2);
    s.push(start);
    visited[a1][a2]=0;
    while (s.empty() == false) {
        pair <int,int> top = s.front();
        s.pop();
        if(top.first == b1 && top.second == b2)
            return visited[b1][b2];
        for(int i=0;i<8;i++){
            int newA=top.first+mX[i],newB=top.second+mY[i];
            if(validPosition(newA,newB)){
                if(visited[newA][newB] == 0){
                    visited[newA][newB] = visited[top.first][top.second]+1;
                    pair <int,int> node (newA,newB);
                    int pi= ((newA-1)*8)+newB;
                    int pj= ((top.first-1)*8)+top.second;
                    path[pi]=moves[i];
                    route[pi]=pj;
                    s.push(node);
                }
            }
        }
     }
}

void printpath(int a, int b){
  if(a==b){return;}
  printpath(route[a],b);
  cout<<endl<<path[a];
}

int main(){
    string node1,node2;
    string m = "abcdefgh";
    cin>>node1>>node2;
    int a1,a2,b1,b2;
    memset (visited,0,sizeof visited);
    a2 = m.find(node1[0])+1;   
    b2 = m.find(node2[0])+1;
    a1=atoi(&node1[1]);
    b1=atoi(&node2[1]);
    cout<<bfs(a1,a2,b1,b2);
    printpath((((b1-1)*8)+b2),(((a1-1)*8)+a2));
 return 0;   

}
