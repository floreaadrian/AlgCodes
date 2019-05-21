#include<bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	int ins,d,w;
	int n,m;
	string s,t;
	int ex[26][26];
	scanf("%d",&tc);
	vector<string> oop;
	vector<int> oopi;
	while(tc--) {
		cin>>s;
		cin>>t;
		n=s.size();
		m=t.size();
		scanf("%d%d%d",&ins,&d,&w);
		oop.clear();
		oopi.clear();
		for(int i=0;i<26;++i)
		 for(int j=0;j<26;++j)
		  ex[i][j]=1;
		deque<int> dic[26];
		for(int i=0;i<n;++i) dic[s[i]-65].push_back(i);
		for(int i=0;i<min(m,n);++i) {
			if(s[i]!=t[i] && !(dic[t[i]-65].empty()) && min(ins+d,ex[s[i]-65][t[i]-65])>w) {
				while(!(dic[t[i]-65].empty()) && dic[t[i]-65].front()<i) dic[t[i]-65].pop_front();
				if(!(dic[t[i]-65].empty())) {
					swap(s[dic[t[i]-65].front()],s[i]);
					oop.push_back("S "+to_string(i+1)+" "+to_string(dic[t[i]-65].front()+1));
				}
			}
		}
		int i=0;
		while(i<n && i<m) {
			if(s[i]!=t[i]) {
				if((ins+d)>ex[s[i]-65][t[i]-65])
				 oop.push_back("R "+to_string(i+1)+" "+t[i]);
				else {
					oop.push_back("D "+to_string(i+1));
					oop.push_back("I "+to_string(i)+" "+t[i]);
				}
			}
			i++;
		}
		while(i<n) {
			oop.push_back("D "+to_string(i+1));
			i++;
		}
		while(i<m) {
			oop.push_back("I "+to_string(i)+" "+t[i]);
			i++;
		}
	printf("%d\n",oop.size());
	for(auto it: oop)cout<<it<<"\n";
	}
	return 0;
}
