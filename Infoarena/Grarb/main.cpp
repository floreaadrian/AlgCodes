#include <fstream>
#include <vector>
#include <bitset>

using namespace std;

ifstream fin("grarb.in");
ofstream fout("grarb.out");

vector <int> v[100001];
bitset <100001> seen;
int n,m,nr;

void df(int node)
{
    seen[node]=1;
    int nrn=v[node].size();
    for(int i=0;i<nrn;i++)
        if(!seen[v[node][i]])
        df(v[node][i]);
}

int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(!seen[i])
        {
            df(i);
            nr++;
        }
    fout<<m+nr-n<<"\n";
    fout<<nr-1;

    return 0;
}
