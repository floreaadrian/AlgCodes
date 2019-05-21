#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;

ifstream fin("date.in");

bool a[10005][10005];

int main()
{
    char s[100005];
    cin>>s;
    int ln=strlen(s);
    int x=0,y=0,c=0;
    for(int i=0;i<ln;++i)
    {
        if(s[i]=='L'){
            y--;
            if(a[x][y])c++;
            else a[x][y]=true;
        }else
        if(s[i]=='R'){
            y++;
            if(a[x][y])c++;
            else a[x][y]=true;
        }else
        if(s[i]=='U'){
            x--;
            if(x<0)x1=10005+x;
            if(a[x][y])c++;
            else a[x][y]=true;
        }else
        if(s[i]=='D'){
            x++;
            if(a[x][y])c++;
            else a[x][y]=true;
        }
    }
    printf("%d",c);
}
