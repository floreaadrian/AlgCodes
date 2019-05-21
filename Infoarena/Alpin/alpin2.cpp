#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <stack>
#include <deque>
#include <iomanip>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <list>
#include <iomanip>
 
using namespace std;
 
string file = "alpin";
 
ifstream cin( (file + ".in").c_str() );
ofstream cout( (file + ".out").c_str() );
 
const int MAXN = 1030;
const int oo = 0x3f3f3f3f;
const int dx[] = {1, 0, -1,  0};
const int dy[] = {0, 1,  0, -1};
 
typedef vector<int> Graph[MAXN];
typedef vector<int> :: iterator It;
 
const inline int min(const int &a, const int &b) { if( a > b ) return b;   return a; }
const inline int max(const int &a, const int &b) { if( a < b ) return b;   return a; }
const inline void Get_min(int &a, const int b)    { if( a > b ) a = b; }
const inline void Get_max(int &a, const int b)    { if( a < b ) a = b; }
 
int N, A[MAXN][MAXN], D[MAXN][MAXN];
pair<int, int> Father[MAXN][MAXN], Ans;
 
struct ClassComp {
    inline bool operator () (const pair<int, int> &a, const pair<int, int> &b) const {
        return D[a.first][a.second] < D[b.first][b.second];
    }
};
 
void Fill(int x, int y) {
    int minval = oo;
    D[x][y] = 1;
    for(int d = 0 ; d < 4 ; ++ d) {
        int xnou = x + dx[d];
        int ynou = y + dy[d];
        if(xnou >= 1 && xnou <= N && ynou >= 1 && ynou <= N)
            if(A[x][y] < A[xnou][ynou]) {
                if(!D[xnou][ynou])
                    Fill(xnou, 	ynou);
                if(D[x][y] < D[xnou][ynou] + 1) {
                    D[x][y] = D[xnou][ynou] + 1;
                    Father[x][y] = make_pair(xnou, ynou);
                }
            }
    }
    Ans = max(Ans, make_pair(x, y), ClassComp());
}
 
int main() {
    cin >> N;
    for(int i = 1 ; i <= N ; ++ i)
        for(int j = 1 ; j <= N ; ++ j)
            cin >> A[i][j];
    for(int i = 1 ; i <= N ; ++ i)
        for(int j = 1 ; j <= N ; ++ j)
            if(!D[i][j])
                Fill(i, j);
    cout << D[Ans.first][Ans.second] << '\n';
    do {
        cout << Ans.first << ' ' << Ans.second << '\n';
        Ans = Father[Ans.first][Ans.second];
    } while(D[Ans.first][Ans.second]);
    cin.close();
    cout.close();
    return 0;
}
