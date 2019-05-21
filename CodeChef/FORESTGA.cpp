#include<bits/stdc++.h>

using namespace std;

vector < pair< long long  , long long > > v;
vector < pair< long long  , long long > > a;

int main()
{
    long long  n,w,l,i;
    scanf("%lld",&n);
    scanf("%lld",&w);
    scanf("%lld",&l);
    long long  oo=0x3f3f3f3f;
    for(int i=0;i<n;++i){
        long long  x,y;
        scanf("%lld",&x);
        scanf("%lld",&y);
        v.push_back( make_pair(x,y) );
        long long  val =(l-v[i].first)/v[i].second;
        if((l-v[i].first)%v[i].second!=0 )
        val+=1;
        a.push_back(make_pair(val,i));
        }
    long long  sum=0,con=0;
    sort(a.begin(),a.end()) ;
    long long  constant =0;
    oo= a[0].first;
    con=oo;
     sum += constant;
     for(i=0;i<a.size();i++)
     {
		  long long  val = a[i].first;
		  long long  indice= a[i].second;
		  long long  next =a[i+1].first;
		  if(i>0)
		  sum+= (constant * (a[i].first-a[i-1].first) );
              sum+=v[indice].first;
              sum+= (v[indice].second * val);
              constant+= v[indice].second;
         con=a[i].first;
         if(sum>=w)
		 break;
	     long long  k= val+1;
		 long long  sumcheck=sum;
		 long long  gap = next-k;
         long long  gapval;
         if(constant!=0){
			 gapval = (w-sum)/constant;
		if((w-sum)%constant!=0)
       	gapval+=1;
		 }
         if(gapval<=gap)
         {
			 con+= gapval;
			 break;
		 }
	 }
    printf("%lld\n",con);
    return 0;
}
