#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("data.in");
ofstream fout("data.out");

bool check(long nr)
{
    string strNr = to_string(nr);
    if (strNr.find('4') == string::npos)
        return true;
    return false;
}

int main()
{
    long n;
    fin >> n;
    for (long tt = 1; tt <= n; ++tt)
    {
        long k;
        fin >> k;
        fout << "Case #" << tt << ": ";
        long a = k, b = 0;
        while (true)
        {
            if (check(a) && check(b))
                break;
            a--;
            b++;
        }
        fout << a << " " << b << "\n";
    }
    return 0;
}