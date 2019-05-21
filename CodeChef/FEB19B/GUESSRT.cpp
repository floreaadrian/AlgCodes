#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define modulo 1000000007

long long power(long long base, long long exp)
{
    base %= modulo;
    long long result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % modulo;
        base = (base * base) % modulo;
        exp >>= 1;
    }
    return result;
}

void gcdExtended(long long a, long long b, long long *x, long long *y)
{

    if (a == 0)
    {
        *x = 0, *y = 1;
        return;
    }

    long long x1, y1;
    gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;
}
long long inverse(long long a, long long m)
{
    long long x, y;
    gcdExtended(a, m, &x, &y);
    return (x % m + m) % m;
}

int main()
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        long long n, k, m;
        cin >> n >> k >> m;
        if (n == 1)
        {
            cout << "1\n";
            continue;
        }
        if (m == 1)
        {
            cout << inverse(n, modulo) << "\n";
            continue;
        }
        long long res;
        if (n > k)
        {
            if (n % k == 0)
                n = k;
            else
                n = n % k;
            m--;
        }
        long long mm = m;
        m = (m + 1) / 2;
        long long a = power(n, m);
        long long b = power(n - 1, m);

        res = (a - b) % modulo;
        res = (res * inverse(a, modulo)) % modulo;
        long long c = 0;
        if (mm % 2 == 0)
        {
            c = (b * inverse(a, modulo)) % modulo;
            c = (c * inverse((n + k) % modulo, modulo)) % modulo;
        }
        res = (res + c) % modulo;
        cout << res << '\n';
    }
    return 0;
}
