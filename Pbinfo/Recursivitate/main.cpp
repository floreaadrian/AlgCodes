#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
int cifminpar(int n)
{
    if(n<10 && n%2==0) return n;
    else{
        int m=cifminpar(n);
        if(m<n%10) return m;
        return n%10;
    }
}

int main()
{
    int a;
    scanf("%d",&a);
    cout<<cifminpar(a);
    return 0;
}
