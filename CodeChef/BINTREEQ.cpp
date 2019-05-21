#include<bits/stdc++.h>
using namespace std;


int main()
{
  long long tc,n,u,v,ls,k;
  cin>>tc;
  while(tc--)
  {
	 stack<long long>s1,s2;
    cin>>n>>u>>v;
    k=u;
    long long ts;
    while(k>1)
    {
     s1.push(k&1);
      ts=k&1;
     k>>=1;
    }
    k=v;
    while(k>1)
    {
     s2.push(k&1);
      ts=k&1;
     k>>=1;
    }
    while(!s1.empty() && !s2.empty() && (s1.top()==s2.top()))
    {
      s1.pop();s2.pop();
    }
    long long h=max(s1.size(),s2.size());
    if(h==0)
    cout<<n<<"\n";
    else
    {
    ls=n/(2<<(h-1));
    bool no=0;
    k=ls;
    while(!s1.empty())
    {
      k=(k<<1)+s1.top();

      s1.pop();
      if(k>n)
      {
        no=1;break;
      }
    }
    k=ls;
    while(!s2.empty())
    {
      k=(k<<1)+s2.top();
      s2.pop();
      if(k>n)
      {
        no=1;break;
      }
    }
    if(no)
      cout<<(ls-1)<<"\n";
    else
      cout<<(ls)<<"\n";
      }
  }
}
