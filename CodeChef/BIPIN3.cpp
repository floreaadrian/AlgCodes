#include <bits/stdc++.h>
#include<string.h>
#define ll long long int
#include <algorithm>
#include<math.h>
#include<cmath>
#define mod 1000000007

using namespace std;

ll i,j,t,n,r,g;

ll modular_pow(ll base, ll exponent)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}


int main() {
    cin>>t;
    while(t--){
        cin>>n>>r;
       cout<<r*modular_pow(r-1,n-1)<<"\n";
    }
	return 0;
}
