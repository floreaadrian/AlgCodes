#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector <int> a;
        for(int i=1;i<=n;++i)
        {
            int k;
            scanf("%d",&k);
            a.push_back(k);
        }
        sort(a.begin(),a.end());
        if(a[1]-a[0]>1){
            printf("%d\n",a[0]);
        }else if(a[n-1]-a[n-2]>1){
            printf("%d\n",a[n-1]);
        }else {
            for(int i=0;i<n;++i)
                if(a[i]==a[i+1])
                printf("%d\n",a[i]);
        }
    }
    return 0;
}
