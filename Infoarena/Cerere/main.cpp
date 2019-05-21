#include <fstream>
#include <vector>
#define manx 100001

using namespace std;

ifstream fin("cerere.in");
ofstream fout("cerere.out");

vector <int> g[manx];
int k[manx],stk[manx],sol[manx],it,n;
bool tata[manx];

void df(int node)
{
    stk[++it]=node;
    if(k[node])
        sol[node]=sol[stk[it - k[node]]] + 1;
    int nr=g[node].size();
    for(int i=0;i<nr;i++)
        df(g[node][i]);
    it--;
}

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
        fin>>k[i];
    for(int i=1;i<n;i++){
        int a,b;
        fin>>a>>b;
        tata[b]=true;
        g[a].push_back(b);
    }
    int i;
    for(i=1;i<=n;i++)
        if(!tata[i])
            break;
        df(i);
    for(i=1;i<=n;i++)
        fout<<sol[i]<<" ";
    return 0;
}
