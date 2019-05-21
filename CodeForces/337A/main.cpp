#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[55],n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
        cin>>a[i];
    sort(a,a+m);
    int best=10000;
    for(int i=0;i<m-n+1;i++)
        best=min(best,a[n+i-1]-a[i]);
    cout<<best;
    return 0;
}
