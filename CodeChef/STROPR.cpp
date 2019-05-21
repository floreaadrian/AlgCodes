#include <iostream>

using namespace std;

int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,x,m,a[100001],sum=0;
        cin>>n>>x>>m;
        for(int i=1;i<=n;++i)
            cin>>a[i];
            x++;
        for(int i=1;i<=m;i++)
            sum+=a[i]*(x--);
        cout<<sum<<"\n";
    }
    return 0;
}
