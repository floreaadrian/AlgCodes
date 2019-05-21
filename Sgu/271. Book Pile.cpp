#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,k;
    vector <string> ar;
    cin>>n>>m>>k;
    bool ok=false;
    deque <string> q;
    for(int i=1;i<=n;++i)
    {
        string b;
        cin>>b;
        if(i<=k)
        q.push_back(b),ok=true;
        else ar.push_back(b);
    }
    while(m--){
        char b[20];
        cin>>b;
        if(ok==true)
            n=k;
        if(b[0]=='R'){
            int al=k-1;
            while(al--)
            {q.push_front(q.back());
            q.pop_back();}
        }else {
            char c[5];
            n++;
            int i=0,r=0;
            while(b[i]!='(')++i;
            ++i;
            memset(c,0,sizeof(c));
            while(b[i]!=')'){
                c[r]=b[i];++i;++r;
            }
          q.push_front(c);
          if(n>k) {
          ar.push_back(q.back());
          q.pop_back();
          n--;
          }
        }
    }
    reverse(ar.begin(),ar.end());
    for(auto it: q)
        cout<<it<<"\n";
    for(auto it: ar)
        cout<<it<<"\n";
    return 0;
}
