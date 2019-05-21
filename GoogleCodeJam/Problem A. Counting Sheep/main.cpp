#include <fstream>
#include <string.h>

using namespace std;

ifstream fin("A-large.in");
ofstream fout("input.out");

int fr[11];

void calc(int a){
    while(a){
        fr[a%10]++;
        a/=10;
    }
}

bool ok()
{
    for(int i=0;i<=9;++i)
        if(fr[i]==0) return false;
    return true;
}

int main()
{
    int t;
    fin>>t;
    for(int tt=1;tt<=t;++tt){
        fout<<"Case #"<<tt<<": ";
        int n;
        fin>>n;
        if(n==0)
        {
            fout<<"INSOMNIA\n";
        }else
        {
            memset(fr,0,sizeof(fr));
            int i=1;
            long long k;
            while(!ok())
            {
                k=n*i;
                calc(k);
                i++;
            }
            fout<<k<<"\n";
        }
    }
    return 0;
}
