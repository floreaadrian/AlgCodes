#include <fstream>
#include <string>

using namespace std;

ifstream fin("B-large.in");
ofstream fout("iesire.out");

int solve(string s)
{
    int ret = 0;
    int nr = s.size() - 1;
    for (int i = 0; i < nr ; i++)
        if (s[i] != s[i + 1])
            ret++;
    if (s[nr] == '-')
        ret++;
    return ret;
}

int main()
{
    int t;
    string s;
    fin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        fin >> s;
        fout << "Case #" << tt << ": " << solve(s) << '\n';
    }

    return 0;
}
