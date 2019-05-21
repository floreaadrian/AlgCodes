#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int a[500005];
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    while(q--)
    {
        int p;
        scanf("%d",&p);
        if(p==1){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]=y;
        }
        else {
        	int x;
            scanf("%d",&x);
            int s=0;
            for(int i=1;i<=n;++i)
            {
                s+=a[i]/x;
            }
            printf("%d\n",s);
        }
    }
    return 0;
}
