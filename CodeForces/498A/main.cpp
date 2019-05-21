#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    int n,m,boys[105],girls[105],ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&boys[i]);
    scanf("%d",&m);
    for(int i=0;i<m;++i)
        scanf("%d",&girls[i]);
    sort(boys,boys+n);
    sort(girls,girls+m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        if(abs(boys[i]-girls[j])<=1)
    {
        girls[j]=1000;
        ans++;
        break;
    }
    printf("%d",ans);
    return 0;
}
