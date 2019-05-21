#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt)
    {
        int n;
        cin >> n;
        int mi = 0;
        vector<int> data;
        long long sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            int o;
            cin >> o;
            data.push_back(o);
            sum += data[i];
            mi = max(i, mi);
        }
        cout << mi << "\n";
    }
    return 0;
}