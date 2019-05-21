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
        int a[10000], d[10000];
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= n; ++i)
            cin >> d[i];
        vector<int> choosen;

        for (int i = 2; i < n; ++i)
            if (d[i] > (a[i - 1] + a[i + 1]))
                choosen.push_back(i);
        if (d[1] > (a[n] + a[2]))
            choosen.push_back(1);
        if (d[n] > (a[n - 1] + a[1]))
            choosen.push_back(n);
        int maximu = 0;
        if (choosen.size() == 0)
            cout << "-1\n";
        else
        {
            for (int de : choosen)
                maximu = max(d[de], maximu);
            cout << maximu << "\n";
        }
    }
    return 0;
}