#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt)
    {
        int n;
        int fr[40] = {0};
        cin >> n;
        int contor = 0;
        for (int i = 1; i <= n; ++i)
        {
            string a;
            cin >> a;
            bool actFr[40] = {false};
            for (int s = 0; s < a.length(); ++s)
            {
                int code = a[s] - 'a';
                if (!actFr[code])
                {
                    fr[code]++;
                    actFr[code] = true;
                }
            }
        }
        for (int i = 0; i < 40; ++i)
            if (fr[i] >= n)
                contor++;
        cout << contor << "\n";
    }
    return 0;
}