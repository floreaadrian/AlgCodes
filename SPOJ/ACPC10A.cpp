#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    while(a!=0 || b!=0 || c!=0)
    {
        if(c-b==b-a) printf("AP %d\n",c+c-b);
        else printf("GP %d\n",c*c/b);
        scanf("%d%d%d",&a,&b,&c);
    }
    return 0;
}
