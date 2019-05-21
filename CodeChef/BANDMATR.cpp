#include <bits/stdc++.h>

using namespace std;

int x=0;

void rrr(int tmp,int k)
{
    if(tmp-2*k<=0)
        printf("%d\n",x);
    else
        {
        x++;
        rrr(tmp-2*k,k-1);
    }
}

void afla(int n,int cnt)
{
    int tmp=cnt-n;
    if(cnt<=n)
    printf("%d\n",x);
    else
    {
    x++;
    rrr(tmp,n-1);
    }
}

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
    {
        x=0;
         scanf("%d",&n);
         int tmp,cnt=0;
            for(i=0;i<n*n;i++)
            {
             scanf("%d",&tmp);
             if(tmp==1)
                cnt++;
            }
        afla(n,cnt);
    }
    return 0;
}
