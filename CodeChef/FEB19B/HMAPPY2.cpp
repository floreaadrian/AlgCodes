#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
long long lcm(long long a, long long b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt)
    {
        long long n, k, a, b;
        cin >> n >> a >> b >> k;
        long long bothCould = n / lcm(a, b);
        if ((n / a) + (n / b) - 2 * bothCould >= k)
            cout << "Win\n";
        else
            cout << "Lose\n";
    }
}
