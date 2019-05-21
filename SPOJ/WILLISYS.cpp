#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

bool verf(long long n)
{
    return (n & (n - 1));
}

int main()
{
    long long n;
    scanf("%lld",&n);
    if(verf(n))printf("TAK");
    else printf("NIE");
    return 0;
}
