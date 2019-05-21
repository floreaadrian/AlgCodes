#include <fstream>

using namespace std;

ifstream fin("distante.in");
ofstream fout("distante.out");

int main()
{
    int n,m,dist[50001],s,t;
    fin>>t;
    while(t--)
    {
        bool ok=true;
        fin>>n>>m>>s;
        for(int i=1;i<=n;fin>>dist[i++]);
            if(dist[s])
            ok=false;
        while(m--){
            int a,b,c;
        fin>>a>>b>>c;
        if(dist[a]>dist[b]+c || dist[b]>dist[a]+c)
            ok=false;
        }
        if(ok==false)
            fout<<"NU\n";
        else
            fout<<"DA\n";
    }
    return 0;
}
