#include <bits/stdc++.h>

using namespace std;

string s;
int i;

void f(int n){
    if(n==0) return;
    if(s[n-1]>s[n]) {
            i=n; s[n-1]--; f(n-1);
    }
    else f(n-1);
}

int main(){
  freopen("B-large.in", "r", stdin);
  freopen("output.out", "w", stdout);
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;++tt){
        cin>>s;
      int n=s.length();
          i=n;  f(n-1);
        bool ok=false;
        for(int j=i;j<n;j++)
           s[j]=9+48;
        printf("Case #%d: ",tt);
        for(int j=0;j<n;j++)
            if(ok==false && s[j]==0+48) continue;
            else{
                    ok=true;
                    printf("%d",s[j]-48);
            }
        printf("\n");
    }
    return 0;
}
