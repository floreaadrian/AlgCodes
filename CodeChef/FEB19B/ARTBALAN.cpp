#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define MOD 1000000007

long long gcdExtended(long long a, long long b, long long *x, long long *y);

long long power(long long x, long long y)
{
    long long res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

long long inverse(long long a, long long m)
{
    long long x, y;
    long long g = gcdExtended(a, m, &x, &y);
    long long res = (x % m + m) % m;
    return res;
}

long long gcdExtended(long long a, long long b, long long *x, long long *y)
{

    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    long long x1, y1;
    long long gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
long long sol(long long n, long long k, long long m)
{
    long long res;
    if (n == 1)
        return 1;
    if (m == 1)
        return inverse(n, MOD);
    if (n > k)
    {
        if (n % k == 0)
            n = k;
        else
            n = n % k;
        m--;
    }
    m = (m + 1) / 2;
    long long a = power(n, m);
    long long b = power(n - 1, m);

    res = (a - b) % MOD;
    res = (res * inverse(a, MOD)) % MOD;
    long long c;
    if (m % 2 == 0)
    {
        c = (b * inverse(a, MOD)) % MOD;
        c = c * inverse((n + k) % MOD, MOD);
    }
    res = (res + c) % MOD;
    return res;
}

int main()
{
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++)
    {
        long long n, k, m;
        cin >> n >> k >> m;
        cout << sol(n, k, m) << endl;
    }
    return 0;
}
