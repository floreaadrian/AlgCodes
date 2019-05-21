#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n,i;
      char s[5];
         cin>>n;
          
           for(i=1;i<=n;++i)
           {
            cin>>s;
             
            if(strlen(s)==5) cout<<3<<endl;
              else
                if((s[0]=='o'&&s[1]=='n')||(s[0]=='o'&&s[2]=='e')||(s[1]=='n'&&s[2]=='e')) cout<<1<<endl;
                  else
                     cout<<2<<endl;               
           }
     
           return 0;
}

