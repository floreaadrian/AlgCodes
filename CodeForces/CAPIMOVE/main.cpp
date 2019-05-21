#include<bits/stdc++.h>

using namespace std;

int main()
{
	int p[50007];
	int t,n;
	int a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector <pair <int,int> > pop;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p[i]);
            pop.push_back(make_pair(p[i],i));
        }
        sort(pop.begin(),pop.end());
        set<int> sor[n+1];
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            sor[a].insert(b);
            sor[b].insert(a);

        }
        int r;
        for(int i=1;i<=n;i++)
            for(int j=n-1;j>=0;j--)
            {
                r=pop[j].second;
                if(sor[i].find(r)==sor[i].end() && i!=r)
                {
                    printf("%d ",r);break;
                }
            }
    }
    return 0;
}
