#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

int n,Val[101], Num[101], Renum[101];
int M[101][101];
long A[101][101],t;
int Ri, Rj, Rs, Re;

int try_start(int s)
{
    int i, j, k;
    int cont = 0;
    for (i = 1; i <= n; i++)
     for (j = 1; j <= n; j++)
      A[i][j] = (i >= s && j >= s && M[i][j]) ? M[i][j] : inf;
    for (k = s; k <= n; k++)
    {
        for (i = s; i <= n; i++)
         if (A[i][k] <= inf)
            for (j = s; j <= n; j++)
             if (A[i][j] > A[i][k] + A[k][j])
                 A[i][j] = A[i][k] + A[k][j];
        for (i = s; i <= k; i++)
         for (j = s; j <= k; j++)
         {
             if (A[i][j] < t)
                 cont = 1;
             if (A[i][j] == t)
             {
                 Ri = i, Rj = j, Rs = Val[s], Re = Val[k];
                 return 0;
             }
         }
    }
    return cont ? 1 : -1;
}

int main()
{
    FILE *fin,*fout;
    fin = fopen("coach.in","r");
    fout = fopen("coach.out","w");
    int T, m;
    fscanf(fin, "%d %d %ld", &n, &m, &T);
    for (int i = 1; i <= n; i++)
    {
        fscanf(fin, "%d", Val + i);
        Renum[i] = Num[i] = i;
    }
    for (int i = 1; i < n; i++)
     for (int j = i+1; j <= n; j++)
     if (Val[i] > Val[j])
     {
         Renum[Num[i]] = j, Renum[Num[j]] = i;
         t = Val[i], Val[i] = Val[j], Val[j] = t;
         t = Num[i], Num[i] = Num[j], Num[j] = t;
     }
    while (m--)
    {

        fscanf(fin, "%d %d %d", &i, &j, &T);
        M[Renum[i]][Renum[j]] = M[Renum[j]][Renum[i]] = T;
    }
    fclose(fin);
    for (int i = 1; i < n; i++)
        if (try_start(i) != 1) break;
    fprintf(fout,"%d %d %d %d\n", Num[Ri], Num[Rj], Rs, Re);
    fclose(fout);
    return 0;
}
