#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n,a[105],x;
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    int mi,k=0;
    for(int i=0;i<n-1;++i)
    {
        mi=i;
        for(int j=i+1;j<n;++j)
        if(a[j]<a[mi]){
            mi=j;
        }
        swap(a[mi],a[i]);
        k++;
        if(k==x)
            break;
    }
    for(int i=0;i<n;++i)
        printf("%d ",a[i]);
    return 0;
}
