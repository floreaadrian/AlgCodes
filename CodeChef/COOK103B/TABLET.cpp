#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt)
    {
        int n, b;
        cin >> n >> b;
        int maxArea = 0;
        for (int i = 0; i < n; ++i)
        {
            int w, h, p;
            cin >> w >> h >> p;
            if (p <= b)
            {
                if (w * h > maxArea)
                    maxArea = w * h;
            }
        }
        if (maxArea == 0)
            cout << "no tablet\n";
        else
            cout << maxArea << "\n";
    }
    return 0;
}