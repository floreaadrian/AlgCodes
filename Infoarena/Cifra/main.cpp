#include<fstream>
#include<cstring>
using namespace std;

ifstream fin("cifra.in");
ofstream fout("cifra.out");

char n[101];
int T,i,v[101];

int Pow(int n)
{
    int p=n,sol=1;
    while(p!=0)
    {
        if(p%2==1)
            sol=(n*sol)%10;
        n=(n*n)%10;
        p/=2;
    }
    return sol;
}

int main()
{
    for(i=1;i<=100;i++)
        v[i]=(v[i-1]+Pow(i))%10;
    fin>>T;
    while(T--)
    {
        fin>>(n+1);
        int s=strlen(n+1);
        if(s==1)
            fout<<v[n[s]-'0']<<"\n";
        else
                fout<<v[n[s]-'0'+(n[s-1]-'0')*10]<<"\n";
    }
    return 0;

}
