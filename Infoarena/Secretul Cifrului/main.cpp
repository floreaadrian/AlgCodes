#include <fstream>
#define MX 2005

using namespace std;

ifstream fin("cifru.in");
ofstream fout("cifru.out");

int a[MX];

int main()
{
int n,k;
fin>>n>>k;
a[0]=1;
for(int i=1;i<=n;++i)
{
    int x=1,y=1;
    while(x<=i && x<=k)
    {
    if(k%x==0)
    a[i]=(a[i]+y*a[i-x])%19997;
    y=(y*(i-x))%19997;
    ++x;
    }
}
fout<<a[n]<<'\n';
return 0;
}
