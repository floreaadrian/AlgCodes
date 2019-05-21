#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    long long t;
    long long arr[100001] = {0};
    cin >> t;
    while (t--)
    {
        long long n, k, m = 0;
        cin >> n >> k;
        for (long long i = 0; i < n; i++)
        {
            long long l, r;
            cin >> l >> r;
            for (long long j = l; j <= r; j++)
                arr[i]++;
        }
        sort(arr, arr + 100000, compare);
        long long j = 0;
        while (arr[j] > k)
        {
            j++;
        }
        for (long long p = j; p >= 0; p--)
        {
            if (n >= arr[p] - k)
            {
                n -= arr[p] - k;
                m++;
            }
        }

        cout << m << endl;
    }
    return 0;
}