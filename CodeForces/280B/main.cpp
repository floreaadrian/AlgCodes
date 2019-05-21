#include <iostream>
#include <math.h>

using namespace std;

int v[1000009];

int main()
{
    int i,j;
    for(i=2;i<=1000;++i)
    if(!v[i]){
			for(j=2*i; j<=1000000; j+=i)
				v[j]++;
    }
    int n;
    cin>>n;
    while(n--){
        long long a,b;
        cin>>a;
        b=sqrt(a);
        if(b*b==a && !v[b] && a!=1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
