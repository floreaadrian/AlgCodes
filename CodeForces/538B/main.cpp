#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,k,w;
    scanf("%d%d%d",&k,&n,&w);
    long long sum = ((w*(w+1))/2)*k;
    if(sum-n<0)cout<<0;
    else
    cout<<sum-n;
    return 0;
}
