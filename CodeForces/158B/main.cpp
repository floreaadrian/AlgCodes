#include <iostream>
#include <stdio.h>

using namespace std;

int a[5];

int maxi(int a,int b)
{
    if(a>b)return a;
    return b;
}

int main()
{
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&k),a[k]++;
    a[1]=max(a[1]-a[3],0);
    printf("%d",a[3]+a[4]+(a[1]+2*a[2]+3)/4);
    return 0;
}
