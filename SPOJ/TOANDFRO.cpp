#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0){
        string s;
        vector <vector<char> > v;
        cin>>s;
        int m=s.size()/n;
        bool directie=true;
        int k=0;
        for(int i=0;i<m;i++)
        {
            vector<char> act;
            for(int j=0;j<n;++j,++k)
                act.push_back(s[k]);
            if(directie)
                reverse(act.begin(),act.end());
            v.push_back(act);
            directie=!directie;
        }
        for(int i=n-1;i>=0;i--)
            for(int j=0;j<m;++j)
                cout<<v[j][i];
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}
