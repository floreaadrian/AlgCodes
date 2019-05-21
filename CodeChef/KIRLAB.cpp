#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int c=0,n,cm=0,a,b;
        scanf("%d",&n);
        scanf("%d",&a);
        for(int i=1;i<n;++i)
        {
            scanf("%d",&b);
            //printf("%d : %d = %d\n",a,b,__gcd(a,b));
            if(a%2==0 && b%2==0)
                c++;
            if(__gcd(a,b)>1)
                c++;
            a=b;
        }
        printf("%d\n",c+1);
    }
    return 0;
}
