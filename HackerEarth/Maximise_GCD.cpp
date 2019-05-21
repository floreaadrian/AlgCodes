#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int a[1000005];
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int ma=0,loc=0;
    for(int i=n-1;i>=1;i--)
    {
        int cmm=__gcd(a[i+1],a[i]);
        if(cmm>=ma){
            ma=cmm;
            loc=n;
        }
        printf("%d\n",loc);
    }
    return 0;
}
