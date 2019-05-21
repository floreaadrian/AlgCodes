#include <iostream>
#include <string.h>
#define INF 1000000007

using namespace std;

inline long long getMin(long long a,long long b){ return a>b ? b:a ;}
long long v[100005];
long long sum[100005];
long long revSumI[100005];
long long diff[100005];
long long seg[100005];
long long si[100005];

long long findAns(long long n){
	if(n==0){
		return v[0];
	}
	bool loop = true;
	long long min = v[0];
	for(long i=0;i<=n;++i){
		if(v[i]>0){
			loop=false;
		}
		if(min<v[i]){
			min = v[i];
		}
	}
	if(loop==true) return min;
	long long ans = sum[n];
	if(v[0]>ans){
		ans = v[0];
	}
	if(v[n]>ans){
		ans = v[n-1];
	}
	for(long i=1;i<=n-1;++i){
		long long left = si[i-1];
		long long right = revSumI[i+1];
		long long temp=0;
		if(v[i]<0){
			long long temp1 = sum[right] - sum[i];
			long long temp2 = sum[i-1] - sum[left];
			if(temp1<0) temp1 = 0;
			if((temp2<0)) temp2 =0;
			temp = temp1+temp2;
			if(temp > ans){
				ans = temp;
			}
		}

	}
	return ans;
}

int main()
{
	long long t;
	cin>>t;
	while(t--){
		memset(v,0,sizeof(v));
		memset(sum,0,sizeof(sum));
		memset(seg,0,sizeof(seg));
		sum[-1]=0;
		long long ans = 0;
		long long  N;
		cin>>N;
		for(long i=0;i<=N-1;++i){
			cin>>v[i];
		}
		sum[0]=v[0];
		for(long i=1;i<=N-1;++i){
			sum[i]=v[i]+sum[i-1];
		}
		sum[N]=sum[N-1];
		si[0]=-1;
		revSumI[N-1]=N;
		for(long i=1;i<=N-1;++i){
			if(si[i-1]!=-1){

				if(sum[i-1]<sum[si[i-1]]){
					si[i]=i-1;
				}
				else{
					si[i]=si[i-1];
				}
			}
			else{
				if(sum[i-1]<0){
					si[i]=i-1;
				}
				else{
					si[i]=si[i-1];
				}
			}
		}
		for(long i = N-2 ; i>=0 ; i--){
			if(revSumI[i+1]!=N){

				if(sum[i]>sum[revSumI[i+1]]){
					revSumI[i]=i;
				}
				else{
					revSumI[i]=revSumI[i+1];
				}
			}
			else{
				if(sum[i]>sum[N]){
					revSumI[i]=i;
				}
				else{
					revSumI[i]=revSumI[i+1];
				}
			}
		}
		ans=findAns(N-1);
		cout<<ans<<"\n";
	}
    return 0;
}
