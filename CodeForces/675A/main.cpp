#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(c==0){
        if(a==b)cout<<"YES";
        else cout<<"NO";
    }else
    if((b - a) % c == 0 && (b - a) / c >= 0)
        cout<<"YES";
    else cout<<"NO";
    return 0;
}
