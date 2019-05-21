#include <stdio.h>
#include<math.h>
int main(void) {
	int t;
	scanf("%d",&t);
	while(t--){
		long long int n,m;
		bool ok=false;
		scanf("%lld%lld",&n,&m);
		int v[100005];
		long long int l;
		for(l=0;l<n+1;l++)
		    v[l]=-1;
		while(m--)
		{
		    long long int i,j,val;
		    scanf("%lld %lld %lld",&i,&j,&val);
		    if(i!=j && !ok){
		    if(v[i]==-1 && v[j]==-1)
		    {
		        if(val==1) v[i]=1,v[j]=2;
		        else v[i]=v[j]=1;
		    }
		    else if(v[i]==-1 && v[j]>=0)
		    {
		        if(val==0)
		            v[i]=v[j];
		        if(val==1)
		        {
		            if(v[j]==1)
		            v[i]=2;
		            else
		            v[i]=1;
		        }
		    }
		    else if(v[i]>=0 && v[j]==-1)
		    {
		        if(val==0)
		            v[j]=v[i];
		        if(val==1)
		        {
		            if(v[i]==1)
		            v[j]=2;
		            else
		            v[j]=1;
		        }
		    }
		    else if(v[i]>=0 && v[j]>=0)
		    {
		        if(val==0 && (v[i]-v[j]!=0))
		         ok=true;
		        if(val==1 && (abs(v[i]-v[j])!=1))
		         ok=true;
		    }
		   }
		   else if(i==j && val==1)
			ok=true;
		}
		if(!ok)
		printf("yes\n");
		else
		printf("no\n");
	}
	return 0;
}
