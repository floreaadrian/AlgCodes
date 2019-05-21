#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    string s;
    while (t--)
    {

        vector<long long> vec;
        map<long long, long long> ma;
        long long n;
        string s;
        cin >> n;
        cin >> s;
        char c = s[0];
        for (int i = 1; i < s.length(); i++)
            if (s[i] == c)
                vec.push_back(i);
        long long ans = 0;
        for (int p = 0; p < vec.size(); p++)
        {
            ans = 0;
            for (int i = 1; i < vec[0]; i++)
                if (s[i] == s[vec[p] + i])
                    ans++;
                else
                {
                    ma[ans]++;
                    break;
                }
        }
        long long d = 0;
        for (auto x : ma)
            if (d < x.second)
                d = x.second;
        if (d == 0)
            d = n - 1;
        for (int i = 0; i <= d; i++)
            cout << s[i];
        cout << "\n";
    }
}
