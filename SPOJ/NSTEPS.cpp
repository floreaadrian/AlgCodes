#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x!=y && x-2!=y)
        {
            printf("No Number\n");
        }else{
            if(x%2==0 && b%2==0)
            printf("%d\n",x+y);
            else printf("%d\n",x+y-1);
        }
    }
    return 0;
}
