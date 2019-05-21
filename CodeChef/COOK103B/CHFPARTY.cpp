#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt)
    {
        int n, b;
        cin >> n;
        vector<int> persone;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            persone.push_back(a);
        }
        sort(persone.begin(), persone.end());
        int persoaneVenite = 0;
        for (int i = 0; i < persone.size(); ++i)
            if (persoaneVenite >= persone[i])
            {
                persoaneVenite++;
            }
        cout << persoaneVenite << "\n";
    }
    return 0;
}