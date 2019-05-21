#include <iostream>

using namespace std;

int main()
{
    int n,k,i;
    cin>>n>>k;
    k=240-k;
    for(i=1;k>=5*i&&i<=n;++i)k-=5*i;
    cout<<i-1;
    return 0;
}
