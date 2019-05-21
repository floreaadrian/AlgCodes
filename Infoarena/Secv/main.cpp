#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("secv.in");
ofstream fout("secv.out");

int n,i,j,a[50055],k,v[50055],sol,best=1<<30;
bool avem[2000000001];

int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
        if(!avem[a[i]]){
            ++k;
            v[k]=a[i];
            avem[a[i]]=true;
        }
    }
    sort(v+1,v+k+1);
    for(i=1;i<=n;i++){
        if(a[i]==v[1])
        {
            int indice=1;
            for(j=i+1;j<=n+1;j++)
            {
                if(indice==k){
                    sol=j-i;
                    if(sol<best)
                        best=sol;
                    break;
                }
                if(a[j]==v[indice+1])
                    indice++;
            }
        }
    }
    if(best==1<<30)
        fout<<"-1\n";
    else fout<<best<<"\n";
    return 0;
}
