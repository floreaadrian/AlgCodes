#include <iostream>
#include <string.h>

using namespace std;

bool ver[50],alt[50];

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n=0,r=0,k=0;
        char a1[1000001],a2[1000001];
        cin>>a1;
        cin>>a2;
        memset(ver,false,50);
        memset(alt,false,50);
        int mar=strlen(a1);
        for(int i=0;i<mar;++i)
        {
            if(a1[i]==a2[i])
                {n++;
                alt[a1[i]-'a']=true;
                }
            for(int j=0;j<mar;++j)
            if(a1[i]==a2[j] && i!=j && !ver[a1[i]-'0'] && a1[i]!=a2[i] && a1[j]!=a2[j])
            {
                r++;
                ver[a1[i]-'0']=true;
            }
        }
        k=mar-n-r;
        /*for(int i=0;i<26;++i)
            if(!alt[i])
            k++;*/
        cout<<n<<"N"<<r<<"J"<<k<<"S\n";
    }
    return 0;
}
