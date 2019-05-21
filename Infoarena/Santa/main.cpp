#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int nmax = 45004;
int op[nmax], viz[nmax], niv[nmax], l[nmax];
vector <int> v[nmax], sol, starts;
stack <int> stiva;
vector <vector <int> > comp;
void solve(int x, int y)
{
if (op[y] == 0)
{
    while(stiva.top() != y)
        stiva.pop();
    stiva.pop();
    return;
}
    starts.push_back(x);
    vector <int> c;
    while (stiva.top() != y){
            c.push_back(stiva.top());
    stiva.pop();
}
    stiva.pop();
    c.push_back(y);
    c.push_back(x);
    comp.push_back(c);}
void dfs (int k, int dad, int lvl){niv[k] = l[k] = lvl;viz[k] = 1;
    for (int i = 0; i < v[k].size(); i++){
            if (v[k][i] == dad)continue;
if (viz[v[k][i]] == 0){
        stiva.push(v[k][i]);
    dfs(v[k][i], k, lvl + 1);
    l[k] = min (l[k], l[v[k][i]]);
    if (op[v[k][i]] == 1)op[k] = 1;
    if (l[v[k][i]] >= niv[k]){
    solve (k, v[k][i]);
}}
    else l[k] = min (l[k], niv[v[k][i]]);
}}
bool backoff (int k, int k_maxi, int nod, int stop){
    viz[nod] = 1;if (k > 1)sol.push_back(nod);
    if (k == k_maxi){if (nod == stop || stop == 0)
        return true;viz[nod] = 0;sol.pop_back();
    return false;}for (int i = 0; i < v[nod].size(); i++)
    if((v[nod][i]!=stop||k==k_maxi-1)&&viz[v[nod][i]]==0&&backoff(k + 1, k_maxi, v[nod][i], stop) == true)
        return true;
    viz[nod] = 0;
    sol.pop_back();
    return false;}
    int kill;
void what(vector <int> &g, int start, int stop)
{
    for (int i = 0 ; i < g.size(); i++)
    {
            viz[g[i]] = 0;
    }
    if (backoff(1, g.size(), start, stop) == false){kill = 1;}}
int main()
{
    int n ,m ,x ,y, e, q, source;
    ifstream cin ("santa.in");ofstream cout ("santa.out");
    cin >> n >> m;
    for (int i = 1; i <= m; i++){cin >> x >> y;v[x].push_back(y);v[y].push_back(x);
}
    cin >> source >> e >> q;op[source] = 1;
    starts.push_back(0);
    comp.push_back(starts);
    dfs(e, 0, 1);if (op[e] == 0){
        cout << "No chance\n";
        return 0;}
    if (find(comp[1].begin(), comp[1].end(), q) == comp[1].end()){reverse(comp.begin() + 1, comp.end());
    reverse(starts.begin(), starts.end());
}
    if (find(comp[1].begin(), comp[1].end(), q) == comp[1].end()){
            cout << "No chance\n";
    return 0;
    }
    starts[0] = q;
    starts[starts.size() - 1] = 0;
    sol.push_back(q);
    for (int i = 1 ; i < comp.size() && kill == 0; i++)
        what(comp[i], starts[i - 1], starts[i]);
    if (kill == 1) {
            cout << "No chance\n";
    return 0;
    }
    cout << sol.size() << "\n";
    for (int i = 0 ; i < sol.size(); i++)
        cout << sol[i] << " " ;
    return 0;
}
