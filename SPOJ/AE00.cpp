#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main ()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=1;i<=sqrt(n);++i)
        for(int j=i+1;i*j<=n;++j)
            cnt++;
    cnt+=sqrt(n);
    printf("%d",cnt);
    return 0;
}
