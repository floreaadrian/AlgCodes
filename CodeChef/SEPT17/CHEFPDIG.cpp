#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s;
	    cin>>s;
	    int ln=s.length();
        bool fr[26]={false};
        int nr[10]={0};
	    for(int i=0;i<ln;++i)
        {
            nr[s[i]-'0']++;
        }
        for(int i=0;i<=9;++i){
            for(int j=0;j<=9;++j)
            if(i!=j)
                if(nr[i] && nr[j]){
                    int k=i*10+j;
                    if(k>=65 && k<=90)
                        fr[k-65]=true;
                }
            if(nr[i]>1)
    	    {
    	        int k=(i)*10+i;
    	        if(k>=65 && k<=90)
    	           fr[k-65]=true;
    	    }
        }
	    for(int i=0;i<26;i++)
	       if(fr[i])
	          cout<<char(i+65);
	    printf("\n");
    }
    return 0;
}
