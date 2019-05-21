#include <fstream>

using namespace std;

ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

int main()
{
    int a,b;
    fin>>a>>b;
    int r=gcd(a,b);
    if(r==1)
        fout<<0;
    else fout<<r;
    return 0;
}
