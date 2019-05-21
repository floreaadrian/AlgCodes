#include <fstream>

using namespace std;

ifstream fin ("matrix.in");
ofstream fout ("matrix.out");

int N,M,contor=0;
char a[1001][1001],x,c,ok[1001][1001];
int v[130],s[1001][1001];

int main ()
{
    fin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            fin>>a[i][j];
    for (int i=1;i<=M;i++)
        for (int j=1;j<=M;j++)
        {
            fin>>x;
            v[x]++;
        }
    for (c='a';c<='z';c++)
    {
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            {
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
                if(a[i][j]==c)
                    s[i][j]++;
            }

        for(int i=M;i<=N;i++)
            for(int j=M;j<=N;j++)
                if(s[i][j]-s[i-M][j]-s[i][j-M]+s[i-M][j-M]!=v[c])
                    ok[i][j]=1;

    }
    for(int i=M;i<=N;i++)
        for(int j=M;j<=N;j++)
            if(ok[i][j]==0)
                contor++;
    fout<<contor;
    return 0;
}
