#include <fstream>

using namespace std;

ifstream fin("farfurii.in");
ofstream fout("farfurii.out");
int n;
long long k;
int main()
{
    fin>>n>>k;
    int urm=1;
    for(int i=1;i<=n;i++)
    {
        long long perm=n-i;
        perm=perm*(perm-1)/2;
        if(k<=perm)
        {
            fout<<urm<<" ";
            urm++;
        }
        else{
            long long aux=urm+k-perm;
            k=perm;
            fout<<aux<<" ";
            for(int j=n;j>=urm;--j)
                if(j!=aux)
                fout<<j<<" ";
            break;
        }
    }
    return 0;
}
