#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        int nr=0;
        for(int i=0;i<=n;++i)
        nr=nr+i*i;
        printf("%d\n",nr);
        scanf("%d",&n);
    }
    return 0;
}
