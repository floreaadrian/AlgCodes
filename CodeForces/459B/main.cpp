#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long n;
    int a[200005],min1=INT_MAX,max1=0;
    cin>>n;
    long long cnt1=0,cnt2=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        max1=max(max1,a[i]);
        min1=min(min1,a[i]);
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]==max1)cnt1++;
        if(a[i]==min1)cnt2++;
    }
    cout<<max1-min1<<" ";
    if(max1==min1)cout<<(n*(n-1))/2;
    else cout<<cnt1*cnt2;
    return 0;
}
