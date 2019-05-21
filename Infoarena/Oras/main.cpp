#include <fstream>
#include <bitset>

using namespace std;

ifstream fin("oras.in");
ofstream fout("oras.out");

const int MAXN = 205;
const int oo = 0x3f3f3f3f;

bitset <MAXN> G[MAXN];

inline void BuildGraph(int N) {
    if(N == 3) {
        G[1][2] = G[2][3] = G[3][1] = 1;
        return;
    }
    if(N == 6) {
        G[1][2] = G[1][3] = G[1][4] = 1;
        G[2][3] = G[2][4] = G[2][5] = 1;
        G[3][4] = G[3][6] = 1;
        G[4][5] = G[4][6] = 1;
        G[5][1] = G[5][3] = G[5][6] = 1;
        G[6][1] = G[6][2] = 1;
        return;
    }
    for(int i = 1 ; i <= N - 2; ++ i)
        G[i][N-1] = G[N][i] = 1;
    G[N-1][N] = 1;
    BuildGraph(N-2);
}

int main() {
    int N;
    fin >> N;
    if(N == 4) {
        fout << "-1\n";
        return 0;
    }
    BuildGraph(N);
    for(int i = 1 ; i <= N ; ++ i, fout << '\n')
        for(int j = 1 ; j <= N ; ++ j)
            fout << G[i][j];
    fin.close();
    fout.close();
    return 0;
}
