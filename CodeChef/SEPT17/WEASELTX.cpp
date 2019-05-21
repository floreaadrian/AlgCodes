#include<bits/stdc++.h>

using namespace std ;

#define mod 1000000007

set < long long > s ;
set < long long > :: iterator it ;
vector < int > tree[200005] ;

int n , q;
long long a[200005] ;
long long heixor[200005] ;
long long maxhei = 0LL ;
long long pt[100] ;

void dfs(int node ,  int par  , long long hei)
{
	int i ;
	heixor[hei]^=a[node] ;
	maxhei = max(maxhei,hei) ;
	for(i = 0; i < tree[node].size() ; i++ )
	{
		int y = tree[node][i] ;
		if(y == par)
		continue ;
		dfs(y,node,hei+1LL) ;
	}
    return ;
}
long long func(long long x, long long y)
{
	if(x == 1 || y == 1)
	return 1LL ;
	if(x == y)
	return 0LL;
	long long minn= min(x,y) ;
	long long maxx = max(x,y);
	long long temp = 1 ;
	it = s.lower_bound(minn) ;
	if(*it>=maxx)
	return 0LL;
	return func(minn,maxx%(*it));
}
int main()
{
    int i , j , t ;
    scanf("%d",&n);
    scanf("%d",&q);
    for(i=1;i<=n-1;i++)
    {
    	int x,y;
    	scanf("%d %d",&x,&y) ;
    	tree[x].pb(y) ;
    	tree[y].pb(x) ;
    }
    for(i=0;i<n;i++)
    {
    	scanf("%lld",&a[i]) ;
    }
    dfs(0,-1,1LL) ; 
    pt[0]=1LL;
    pt[1]=1LL;
    for(i=2;i<=63;i++)
    {
        pt[i] = pt[i-1]*2LL;
        s.insert(pt[i]);
    }
    s.insert(1LL);
    long long moder;
    for(i=1;i<=50;i++)
    {
    	if(pt[i]>=maxhei)
    	{
    		moder = pt[i];
    		break;
    	}
    }
    while(q--)
    {
    	long long x ;
    	scanf("%lld",&x) ;
    	long long ans = 0LL;
    	x%=moder;
    	if(x==0)
    	{
    		printf("%lld\n",a[0]);
    		continue;
    	}
    	long long work ;
    	long long cycle ;
    	int fg=0;
    	for(i=1;i<=40;i++)
    	{
    		if(pt[i]&x&&fg==0)
    		{
    			fg=1;
    			work=pt[i];
    		}
    		if(pt[i]>=x)
    		{
    			cycle=pt[i];
    			break;
    		}
    	}
    	for(long long i = 1LL ; i <= maxhei ; i+=work)
    	{
    		if(func(x,i))
    		{
    		ans ^= heixor[i] ;
    		}
    	}
    	printf("%lld\n",ans) ;
    }
    return 0 ;
}
