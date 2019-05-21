#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

int main()
{
    int a,b,t;
    fin>>t;
    while(t--){
        fin>>a>>b;
        fout<<gcd(a,b)<<"\n";
    }
    return 0;
}
