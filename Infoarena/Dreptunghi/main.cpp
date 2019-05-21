#include <stdio.h>

using namespace std;

int n,m;
long long sol;

int cmmdc(int x, int y)
{
    int r;
    while(y)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    FILE *fin,*fout;
    fin = fopen("dreptunghiuri.in","r");
    fout = fopen("dreptunghiuri.out","w");
    fscanf(fin,"%d%d",&n,&m);
    n--; m--;
    sol = 1LL * n * (n+1) * m * (m+1) / 4;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(cmmdc(i, j) == 1)
            {
                for(int k=1; k*i <= n && k*j <= m; k++)
                {
                    for(int l=1; k*i + l*j <= n && k*j + l*i <= m; l++)
                    {
                        sol += (n - k*i - l*j + 1) * (m - k*j - l*i + 1);
                    }
                }
            }
        }
    }
    fprintf(fout,"%lli\n",sol);
    return 0;
}
