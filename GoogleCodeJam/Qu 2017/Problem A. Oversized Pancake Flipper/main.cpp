#include <bits/stdc++.h>

using namespace std;

int main(){
  	int t;
  	freopen("A-large.in","r",stdin);
  	freopen("output.out","w",stdout);
   	scanf("%d",&t);
   	for(int tt=1;tt<=t;tt++){
   		string s;
        cin>>s;
   		int k;
   		cin>>k;
   		int c=0;
   		for(int i=0;i<=s.size()-k;i++){
   			if(s[i]=='-'){
   				for(int j=i;j<i+k;j++){
   					if(s[j]=='-')
   						s[j]='+';
   					else{
   						s[j]='-';
   					}
   				}
   				c++;
   			}
   		}
   		if(s.find('-')==-1)
   			printf("Case #%d: %d\n",tt,c);
   		else
   			cout<<"Case #"<<tt<<": IMPOSSIBLE\n";
   	}
   	return 0;
}
