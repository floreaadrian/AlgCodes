#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n,a,c=0,ma=0,c1=0;
    scanf("%d",&n);
    scanf("%d",&a);
    if(n==1 && a==1){
        printf("0\n");
        return 0;
    }
    if(a==1)c++;else c1=1,ma=1;
    for(int i=1;i<n;++i){
        scanf("%d",&a);
        if(a==1){
            c++;
            ma=max(ma,c1);
            c1=0;
        }else c1++;
    }
    printf("%d\n",c+ma);
    return 0;
}
