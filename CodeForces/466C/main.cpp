#include <iostream>
#include <stdio.h>

using namespace std;

int a[500005];
long long cnt[500005];

int main()
{
    int n;
    long long s=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    if(s%3!=0)printf("0\n");
    else{
        s/=3;
        long long ss=0;
        for(int i=n-1;i>=0;i--)
        {
            ss+=a[i];
            if(ss==s)cnt[i]=1;
        }
        for(int i=n-2;i>=0;i--)
            cnt[i]+=cnt[i+1];
        long long ans=0;
        ss=0;
        for(int i=0 ; i+2<n;i++)
        {
            ss+=a[i];
            if(ss==s)
                ans+=cnt[i+2];
        }
       cout<<ans<<"\n";
    }
    return 0;
}
