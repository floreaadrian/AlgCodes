#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("noroc.in");
ofstream fout("noroc.out");

int main()
{
    double n,m;
    fin>>n>>m;
    double res = double(1) - double(n)/m;
    if(res < 0.0f) res = 0.0f;
    fout<<fixed<<setprecision(7)<<res;
    return 0;
}
