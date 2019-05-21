#include <fstream>

using namespace std;

int main()
{
    int n, i, p, b;
    ifstream fin("fructe.in");
    ofstream fout("fructe.out");
    fin >> n;
    for(i = 1; i <= n; ++i)
    {
        fin >> p >> b;
        if(b % 2 == 0)
            fout << 0 << "\n";
        else
            fout << 1 << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
