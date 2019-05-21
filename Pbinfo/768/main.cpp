//1527
#include <iostream>
#include <set>

using namespace std;

int ma[1001][1001],a[11][11];

int main()
{
    int n,m,p;
    cin>>p>>n>>m;
    for(int i=1;i<=p;++i)
        for(int j=1;j<=p;++j)
        cin>>a[i][j];
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
    cin>>ma[i][j];
    int co=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            int c=0;
            for(int ii=i;ii<=i+p;++ii)
            {
                for(int jj=j;jj<=j+p;++j)
                    if(a[p-ii][p-jj]==ma[i][j])
                    c++;
            }
            if(c==p*p)
                co++;
        }
    }
    cout<<co;
    return 0;
}
