#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k;
        scanf("%d",&k);
        int n=k%8;
        if(n==1)printf("%dLB\n",k+3);
        else if(n==2)printf("%dMB\n",k+3);
        else if(n==3)printf("%dUB\n",k+3);
        else if(n==4)printf("%dLB\n",k-3);
        else if(n==5)printf("%dMB\n",k-3);
        else if(n==6)printf("%dUB\n",k-3);
        else if(n==7)printf("%dSU\n",k+1);
        else if(n==0)printf("%dSL\n",k-1);
    }
    return 0;
}
