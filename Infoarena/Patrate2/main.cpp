#include <fstream>

using namespace std;

ifstream fin("patrate2.in");
ofstream fout("patrate2.out");

int n,v[10101];

void prod(int v[],int val)
{
    int i,r=0;
    for(i=1;i<=v[0] || r ; ++i){
        v[i]=val*v[i]+r;
        r=v[i]/10;
        v[i]=v[i]%10;
    }
    v[0]=i-1;
}

int main()
{
    fin>>n;
    v[0]=v[1]=1;
    for(int i=2;i<=n;i++) prod(v,i);
    for(int i=1;i<=n*n;i++) prod(v,2);
    for(int i=v[0];i>=1;i--)
        fout<<v[i];
    return 0;
}
