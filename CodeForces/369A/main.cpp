#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,m,k,a,ans=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a);
        if(a==1)
        {
            if(m==0)
                ans++;
            else m--;
        }else{
            if(k!=0){k--;
            continue;}
            if(m!=0){m--;
            continue;}
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
