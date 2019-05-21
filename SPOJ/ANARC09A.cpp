#include <iostream>

using namespace std;

int main()
{
  int k=0,ans,o,c;
  while(1)
  {
    char s[2001];
    cin>>s;
    if(s[0]=='-')
      break;
    o = c = 0;
    int i = 0;
    while(s[i]!='\0')
    {
      if(s[i]=='{')
        o++;
      else
      {
        o--;
        if(o<0)
        {
          o=1;
          c++;
        }
      }
      i++;
    }
    ans = c+o/2;
    cout<<k+1<<". "<<ans<<"\n";
    k++;
  }
  return 0;
}

