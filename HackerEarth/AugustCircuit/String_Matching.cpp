#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int fr[10];

unsigned combina( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main()
{
    string s;
    cin>>s;
    int ln=s.size();
    for(int i=0;i<ln;++i)
        fr[s[i]-'0']++;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int a;
        scanf("%d",&a);
        printf("%d\n",combina(n,fr[a]));
    }
    return 0;
}
