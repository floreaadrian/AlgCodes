#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int minSal[1005];
        for(int i=0;i<n;++i)
            scanf("%d",&minSal[i]);
        int mny[1005],loc[1005],loc1[1005];
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&mny[i],&loc[i]);
            loc1[i]=loc[i];
        }
        string s;
        long long can=0,sal=0,nema=0;
        for(int i=0;i<n;++i)
        {
            cin>>s;
            priority_queue <pair <int,int> > q;
            q.push(make_pair(-1,-1));
            for(int j=0;j<m;++j)
                if(s[j]=='1' && loc[j]>0)
                    q.push(make_pair(mny[j],j));
            if(q.top().first>=minSal[i])
            {
                can++;
                sal+=q.top().first;
                loc[(q.top().second)]--;
            }
        }
        for(int i=0;i<m;++i)
            if(loc[i]==loc1[i]) nema++;
        printf("%lld %lld %lld\n",can,sal,nema);
    }
    return 0;
}
