#include <iostream>
#include <vector>
 
using namespace std;
 
#define M 1 
#define F (-1)
#define U 0 
#define PB push_back
 
 
vector<int> adj[21000];
short int g[21000]; //gender
 
 
bool DFS(int r){
    bool res = true;
    for(int i = 0; i < adj[r].size(); i++){        
        int v = adj[r][i];          
        if(g[v] == g[r]) return false;
        if(g[v] == U){
            g[v] = -g[r];
            res = res and DFS(v);
        }
    }
    return res;
}
 
 
 
int main(void){
   
    int t = 0; cin >> t;
    for(int tt = 1; tt <= t; tt++){
   
        int n, m; 
        cin>>n>>m;
        for(int i = 0; i < n; i++){
            g[i] = U;
            adj[i].clear();
        }
       
        int x, y;
        for( int i = 0; i < m; i++){
           
            cin>>x>>y;
            adj[x].PB(y); adj[y].PB(x);
        }    
   
        cout<<"Scenario #"<<tt<<":\n",tt;
       
        bool result = true;
        for(int i = 0; i < n; i++){
            if(g[i] == U){
                g[i] = M;
                result = result and DFS(i);
            }
        }
       
        if(result)
            cout<<"No suspicious bugs found!\n";
        else
            cout<<"Suspicious bugs found!\n";
    }
 
    return 0;
}
