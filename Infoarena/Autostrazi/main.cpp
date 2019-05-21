#include <bits/stdc++.h>

using namespace std;

using vi = vector <int>;
const int mod = 30011;
int N,K,S;
int R[101];
vi G[101];
bool Viz[101];

vi DFS(int x)
{
    Viz[x] = 1;
    vi X(S + 1);
    X[0] = 1;
    for (const int& f : G[x])
    {
        if (Viz[f] == 1) continue;

        vi F = DFS(f);
        vi Ax(S + 1);

        for (int i = 0, r; i <= K; ++i)
            for (int k = 0; k + R[i] <= S; ++k)
                for (int j = 0; j + k + R[i] <= S; ++j)
                {
                    r = max(j, k + R[i]);
                    Ax[r] = (Ax[r] + X[j] * F[k]) % mod;
                }
        X = Ax;
    }
    return X;
};


int main()
{
    freopen("autostrazi.in","r",stdin);
    freopen("autostrazi.out","w",stdout);
    scanf("%d%d%d",&N,&S,&K);
    for(int i=1;i<=K;++i)
        scanf("%d",&R[i]);
    for(int i=1;i<N;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vi sol = DFS(1);
    int ss = 0;
    for(int i=0;i<=S;++i)
        ss+=sol[i];
    ss%=mod;
    printf("%d\n",ss);
    return 0;
}
