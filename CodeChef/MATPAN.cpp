#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;++tt)
    {
    	string c;
    	bool fr[27]={false};
    	int cost[27];
    	for(int i=0;i<26;++i)
    	   cin>>cost[i];
    	cin>>c;
        int ln=c.size();
        for(int i=0;i<ln;++i)
            fr[c[i]-'a']=true;
        int s=0;
        for(int i=0;i<26;++i)
            if(fr[i]==false)
                s+=cost[i];
        printf("%d\n",s);
    }
    return 0;
}
