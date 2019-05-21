#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int t,n,k,a[10005],s;
    cin>>t;
    while(t--){
        cin>>n>>k;
        s=0;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=k;i<n-k;++i)
            s+=a[i];
        n-=(k*2);
        double sum=(double)s/n;
        cout<<fixed<<setprecision(6)<<sum<<"\n";
    }
    return 0;
}
