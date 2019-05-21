#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
using namespace std;

int main() {
	ll int n,k,t;
	string s,s2;
	multimap < ll int ,pair<ll int,ll int> > m;
	multimap < ll int ,pair<ll int,ll int> > :: reverse_iterator it;
	multimap < ll int ,pair<ll int,ll int> > :: iterator it1;
	scanf("%lli",&t);
	while(t--){
		int flag=0;
		ll int c=0,c2=0,c1=0,j,y,v,st,sto,k2;
		scanf("%lli%lli",&n,&k);
		cin>>s;
		k2=k;
		s2=s;
		flag=s[0]-'0';
		c=1;
		j=0;
		for(ll int i=1;i<s.length();i++){
			if( (s[i]-'0' )==flag){c++;}
			else{
				m.insert( mp(c, mp(j,j+c-1) ) );
				if(c==1){c1++;}
				if(c==2){c2++;}
				c=1;j=i;
				flag=s[i]-'0';
			}
		}
			m.insert( mp(c, mp(j,j+c-1) ) );
			if(c==1){c1++;}
			if(c==2){c2++;}
 		flag=0;
		while(k!=0){
			it=m.rbegin();
			it1=m.end();
			if( (*it).first==2||(*it).first==1 ){
				flag=1;break;
			}
			v=((*it).first);
			st=(*it).second.first;
			sto=(*it).second.second;
			if(  v%2==0){
				m.insert( mp( v/2-1, mp(st,st+ v/2 -1 -1) ) );
				if(   v/2 ==2 ){c2++;}
				m.insert( mp( v/2, mp(st+v/2,sto) ) );
				if(  v/2-1==2 ){c2++;}
				if(s[st+v/2-1]=='0'){s[st+v/2-1]='1';}
				else {s[st+v/2-1]='0';}
			}
			else{
				if( v/2 ==2 ){c2=c2+2;}
				m.insert( mp( v/2, mp(st,st+ v/2 -1) ) );
				m.insert( mp( v/2, mp(st+v/2+1,sto) ) );
				if(s[st+v/2]=='0'){s[st+v/2]='1';}
				else {s[st+v/2]='0';}

			}
			it1--;
			m.erase(it1);
			k--;
		}
		it=m.rbegin();
		if(flag==0){
			cout<<((*it).first)<<"\n";
		}
		else{
			ll int v1=0,v2=0;
			for(ll int l=0;l<s2.length();l++){
				if(l%2==0 && s2[l]=='0'){v2++;}
				else if (l%2==0 && s2[l]=='1'){v1++;}
				else if (l%2==1 && s2[l]=='0'){v1++;}
				else if (l%2==1 && s2[l]=='1'){v2++;}
			}
			if(v1<=k2 || v2<=k2){
				cout<<"1\n";
			}
			else{
				cout<<"2\n";
			}
		}
		m.clear();
	}
	return 0;
}
