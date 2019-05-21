#include <iostream>
#include <vector>
#include <string.h>

#define DIM 65536
using namespace std;

int n,m,x,y, Rank[DIM],Marked[DIM];
vector <int> Edges[DIM], Stack;

void DFS (int node) {
    Marked[node] = 1;

    vector <int> :: iterator it;
    for (it = Edges[node].begin(); it != Edges[node].end(); it ++) {
        int nextNode = *it;
        if (!Marked[nextNode])
            DFS (nextNode);
    }
    Stack.push_back(node);
    return;
}

int main () {
    while(cin>>n && n)
	{
	cin>>m;
    for (int i = 1; i <= m; i ++) {
        cin>>x>>y;
        Edges[x].push_back(y);
        Rank[y] ++;
    }
    for (int i = 1; i <= n; i ++)
        if (!Rank[i]) DFS (i);
    vector <int> :: reverse_iterator it;
    for (it = Stack.rbegin(); it != Stack.rend(); it ++)
       cout<<*it<<" ";
       cout<<"\n";
    memset(Edges,0,sizeof(Edges));
    memset(Rank,0,sizeof(Rank));
    memset(Marked,0,sizeof(Marked));
    Stack.clear();
   }
    return 0;
}
