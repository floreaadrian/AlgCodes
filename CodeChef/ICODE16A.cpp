#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

int a[1000001];

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,b=10000,co1,co2;
        cin>>n>>co1>>co2;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
            if(gcd(a[i],a[i+1])==1)
                ver[i]=true;
        cout<<b<<" ";
    }
    return 0;
}
