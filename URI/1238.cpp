#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char s[50],t[50];
    int i,n,j,k;
      cin>>n;
        for(k=1;k<=n;++k)
        {
            cin>>s;
              cin>>t;
              i=0;
              j=0;
              while (i<strlen(s)&&j<strlen(t))
                {cout<<s[i]<<t[j];
                i++;j++;
                }
                if (i<strlen(s)) while (i<strlen(s)) {cout<<s[i];    i++;       }
                else while(j<strlen(t)){cout<<t[j];j++;
                                        }
                                        cout<<endl;
        }
    return 0;
}
