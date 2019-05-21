#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

int visited[21];

int bfs(int start, int to, vector< vector<int> > * graph){
  queue<int> s;
  s.push(start);
  visited[start]=0;
  while(s.empty()==false){
    int top = s.front();
    s.pop();
    if(top==to)
      return visited[top];
    int total =graph->at(top).size();
    for (int i = 0; i < total; ++i)
    {
      if(visited[graph->at(top)[i]]==-1){
        visited[graph->at(top)[i]]=visited[top]+1;
        s.push(graph->at(top)[i]);
      }
    }
  }

}

int main(){

  vector< vector<int> > graph(21);
  int i=1,cace=1,numI,numJ,n,start,to;
  while(cin>>numI){
    for (int j = 0; j < numI; ++j)
    { 
      cin>>numJ;
      graph[i].push_back(numJ);
      graph[numJ].push_back(i);
    }    
    if(i==19){
      cin>>n;
      cout<<"Test Set #"<<cace++<<"\n";
      for (int k = 0; k < n; ++k)
      { 
        memset(visited,-1,sizeof(visited));
        cin>>start>>to;
        cout<<start<<" to "<<to<<": "<<bfs(start,to,&graph)<<"\n";
        
      }
      cout<<"\n";
      i=0;
      for (int i = 0; i < 21; ++i)
      {
        graph[i].clear();
      }
      
    }
    i++;
  }
  return 0;
}
