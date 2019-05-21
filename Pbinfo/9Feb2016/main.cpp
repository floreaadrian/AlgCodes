#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("oglindiri.in");
ofstream fout("oglindiri.out");

int main()
{
	int v[101],n;
	fin>>n;
	for(int i=1;i<=n;i++)
        fin>>v[i];
    for(int i=1;i<=n;i++)
        fout<<v[i]<<" ";
    fout<<"\n";
    int m,a,b;
    fin>>m;
    for(int i=1;i<=m;i++)
    {
        fin>>a>>b;
        swap(v[a],v[b]);
    }
    for(int i=1;i<=n;i++)
        fout<<v[i]<<" ";
    return 0;
}
