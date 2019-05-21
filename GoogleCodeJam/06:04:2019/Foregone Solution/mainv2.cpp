#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

ifstream fin("data.in");
ofstream fout("data.out");

using namespace std;

int main()
{
    int n;
    fin >> n;
    for (long tt = 1; tt <= n; ++tt)
    {
        long t;
        fin >> t;
        fout << "Case #" << tt << ": ";
        int si = log10(t) + 1;
        string aS(si, ' ');
        string bS(si, ' ');
        int i = si - 1;
        while (t > 0)
        {
            int rem = t % 10;
            if (rem == 4)
                aS[i] = '3', bS[i] = '1';
            else
                aS[i] = rem + '0', bS[i] = '0';
            i--;
            t /= 10;
        }
        long a = 0, b = 0;
        int l = 0;
        while (l < si)
        {
            a = a * 10 + (aS[l] - '0');
            b = b * 10 + (bS[l] - '0');
            l++;
        }
        fout << a << " " << b << "\n";
    }
    return 0;
}