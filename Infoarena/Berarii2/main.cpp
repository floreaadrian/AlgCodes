#include <vector>
#include <fstream>
#include <bitset>
#include <queue>
#define maxn 1000001

using namespace std;

ifstream fin("berarii2.in");
ofstream fout("berarii2.out");

bitset <maxn> vi;
vector <int> g[maxn];
queue <int> sol,Q ;

void bf()
{
    while(!Q.empty())
    {
    int start = Q.front() ;
    Q.pop() ;
    for(vector <int> ::iterator it = g[start].begin() ; it != g[start].end() ; ++ it)
    if(!vi[*it])
    {
    vi[*it] = 1 ;
    Q.push(*it) ;
    }
    }
}

int main()
{
    int n,m,p;
    fin>>n>>m>>p;
    for(int i=1;i<=m;++i){
        int x,y;
        fin>>x>>y;
        g[y].push_back(x);
    }
    for(int i = 1 ; i <= p ; ++ i)
    {
    int x ;
    fin >> x ;
    vi[x] = 1 ;
    Q.push(x) ;
    }
    bf();
    int cnt = 0 ;
    for(int i = 1 ; i <= n ; ++ i)
    if(!vi[i]){
        cnt++;
        sol.push(i);
    }
    fout <<cnt << "\n" ;

    while(!sol.empty())
    {
    fout << sol.front() << "\n";
    sol.pop() ;
    }
    return 0;
}
