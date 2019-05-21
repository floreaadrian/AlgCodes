#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define	mp make_pair
#define	pb push_back
const double EPS = 1e-8;
const int mod = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;

ifstream fin("C-large.in");
ofstream fout("date.out");

ll power(ll x,ll y){
  ll t=1;
  while(y>0){
    if(y%2) y-=1,t=t*x%mod;
    else y/=2,x=x*x%mod;
  }
  return t;
}

bool isprime[500];
vector<int>primes;
int a[40];
int g[40];
string comp(){
	string s="";
	for(int i=31;i>=0;i--) s.pb(a[i]+'0');
		return  s;
}
int check(int p){
	ll x=0,y=0,t=1;
	for(int i=0;i<16;++i) {x+=t*a[i],y+=t*a[i+16]; t*=p;}
	int l=0;
	assert(x>=0&&y>=0&&t>=0);
	while(primes[l]<100){
		ll z=(x%primes[l])+(t%primes[l])*(y%primes[l]);
		if(z%primes[l]==0) return primes[l];
		l++;
	}
	return -1;
}
int main(){
	fout<<"Case #1:\n";
	for(int i=2;i<500;++i){
		if(isprime[i]==0){
			primes.pb(i);
			for(int j=i+i;j<500;j+=i) isprime[j]=1;
		}
	}
	vector<pair<string,vector<int> > > ans;
	for(int i=0;i<1<<30;++i){
		int f=0;
		a[0]=a[31]=1;
		for(int j=0;j<30;++j) a[j+1]=(i>>j)&1;

		for(int j=2;j<11;++j) {
			int x=check(j); if(x==-1) {f=1;break;}
			g[j]=x;
		}
		if(f==0){
			vector<int> c;
			for(int j=2;j<11;++j) c.pb(g[j]);
			ans.pb(mp(comp(),c));
			string l=comp();
			fout<<l<<" ";
			for(int j=0;j<c.size();++j) fout<<c[j]<<" ";
			fout<<"\n";
		}
		if(ans.size()==500) break;
	}
	for(int i=0;i<ans.size();++i){
		;
	}
  return 0;
}
