#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;++tt)
    {
        int n;
        scanf("%d",&n);
        int c=5,k=0;
        while(n/c>0)
        {
            k=k+n/c;
            c*=5;
        }
        printf("%d\n",k);
    }
    return 0;
}
