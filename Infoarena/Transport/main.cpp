#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("transport.in");
ofstream fout("transport.out");

const int NMax=16005;
int n, a[NMax], k, solutie,M;

bool ok(int m)
{
    int contor=1, suma=0;
    for(int i=1; i<=n; i++)
    {
        if(suma + a[i]<=m) suma += a[i];
        else
            {contor++; suma=a[i];}
    }
    if(k>=contor) return 1;
    else return 0;
}

void binar()
{
    int s, d, mijl;
    s=M; d=16000*16000;
    while(s <= d)
    {
        mijl = (s+d)/2;
        if(ok(mijl))
        {
            solutie=mijl;
            d=mijl-1;
        }
        else s=mijl+1;
    }
}

int main()
{
    fin>>n>>k;
    for(int i=1; i<=n; i++)
    {
    fin>>a[i];
    M = max(M,a[i]);
    }

    binar();
    fout<<solutie<<'\n';
    return 0;
}
