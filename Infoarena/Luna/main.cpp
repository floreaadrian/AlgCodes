#include <fstream>
#include <bitset>

using namespace std;

ifstream fin("luna.in");
ofstream fout("luna.out");

bitset <50001> verf;
int a[51][51],n,m,k;

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j){
        fin>>a[i][j];
        verf[a[i][j]]=true;
    }
    fin>>k;
    for(int i=1;i<=k;++i)
    {
        int l,b,c;
        fin>>l>>b>>c;
        if(verf[l]==false)
            fout<<"Tara de provenienta nu are parcele pe Luna!\n";
        else{
            if(a[b][c]==l || a[c][b]==l)
                fout<<"Cererea poate fi satisfacuta!\n";
            else fout<<"Cererea nu poate fi satisfacuta!\n";
        }
    }
    return 0;
}
