#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    long long a[4][4];
    while(t--)
    {
        long long ma=0;
        for(int i=0;i<3;i++)
        {
            long long sum=0;
            for(int j=0;j<3;j++)
            {
                scanf("%lld",&a[i][j]);
                sum+=a[i][j];
            }
            if(sum%2==0)
                sum--;
            if(ma<sum)
                ma=sum;
        }
        for(int j=0;j<3;j++)
        {
            long long sum=0;
            for(int i=0;i<3;i++)
            {
                sum+=a[i][j];
            }
            if(sum%2==0)
                sum--;
            if(ma<sum)
                ma=sum;
        }
        printf("%lld\n",ma);
    }
}
