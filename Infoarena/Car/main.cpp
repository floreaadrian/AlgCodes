#include<fstream>
#include<vector>
#define MAX_N 505

using namespace std;

int d[(1<<21) + 2];
vector<int>Q[2];
int N,M, sol;
int A[MAX_N][MAX_N];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
ifstream f("car.in");
ofstream g("car.out");

inline int code(int i, int j, int dir) { return ((i<<9) + j + (dir<<18)); }

int SI, SJ, FI, FJ;

inline void decode(int stare, int &i, int &j, int &dir)
{
    j = stare&511;
    dir = stare>>18;
    i = (stare>>9)&511;
}
bool expandeaza(int stare)
{
    int i,j,dir;
    int nstare;
    decode(stare, i,j,dir);
    nstare = code(i,j,(dir+7)%8);
    if(d[nstare] > d[stare] + 1)
    {
        d[nstare] = d[stare] + 1;
        Q[d[nstare]&1].push_back(nstare);
    }
    nstare = code(i,j,(dir+1)%8);
    if(d[nstare] > d[stare] + 1)
    {
        d[nstare] = d[stare] + 1;
        Q[d[nstare]&1].push_back(nstare);
    }
    i += dx[dir], j += dy[dir];
    if(i < 1 || j < 1 || i > N || j > M || A[i][j]) return false;
    nstare = code(i,j,dir);
    if(d[nstare] > d[stare])
    {
        d[nstare] = d[stare];
        Q[d[nstare]&1].push_back(nstare);
    }
    if(i == FI && j == FJ) return true;
    return false;
}
int main()
{
    f>>N>>M>>SI>>SJ>>FI>>FJ;
    int stare, i, j, sol = 0;
    for(i = 1; i <= N; ++i)
        for(j = 1; j <= M; ++j)
            f>>A[i][j];
    for(i = 0; i < (1<<21)+2; ++i) d[i] = 1<<15;
    for( i = 0; i<8; ++i)
    {
        stare = code(SI,SJ,i);
        Q[0].push_back(stare);
        d[stare] = 0;
    }
    while(Q[0].size() + Q[1].size())
    {
        while(Q[sol&1].size())
        {
            stare = Q[sol&1][ Q[sol&1].size() - 1 ];
            Q[sol&1].pop_back();
            if(expandeaza(stare))
            {
                g<<sol<<"\n";
                return 0;
            }
        }
        ++sol;
    }
    g<<"-1\n";
    return 0;
}
