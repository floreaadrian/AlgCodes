#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <string.h>
 
using namespace std;
 
ifstream cin ("lanterna.in");
ofstream cout ("lanterna.out");
 
struct mp{
    int x;
    int y;
    int z;
    mp(int _x, int _y, int _z): x(_x) , y(_y), z(_z){}
};
 
const int   DN = 55,
            DK = 1005,
            oo = ((1<<31)-1);
 
vector < mp > G[DN];
bitset < DN > knowledge;
vector <int> d(DN, oo);
queue < pair<int, int> > Q;
int n, k, m, D[DN][DK];
int answer1 , answer2;
 
inline int bf(int K)
{
    int sol = ((1<<31)-1);
    for(int i = 1 ; i <= n ; ++ i)
        for(int j = 0 ; j <= K; ++ j)
            D[i][j] = oo;
 
    for(Q.push(make_pair(1, 0)), D[1][0] = 0; !Q.empty();  )
    {
        int nod = Q.front().first;
        int nowwats = Q.front().second;
        Q.pop();
        for(vector<mp> :: iterator it = G[nod].begin(); it != G[nod].end(); ++ it)
        {
            int newnode = it->x;
            int time = it->y;
            int watts = it->z;
            if(nowwats + watts <= K)
            {
                int now = nowwats + watts;
                if(knowledge[newnode])
                    now = 0;
                int t = D[nod][nowwats] + time;
                if( t < D[newnode][now])
                {
                    D[newnode][now] = t;
                    Q.push(make_pair(newnode, now));
                    if( newnode == n && t < sol)
                        sol = t;
                }
            }
        }
    }
    return sol;
}
 
 
inline int bs()
{
    int li = 1, ls = k - 1, solution = k, mij;
    while( li <= ls )
    {
        mij=(li+ls)>>1;
        if( bf(mij) == answer1 )
        {
            solution = mij;
            ls = mij - 1;
        }
        else li = mij + 1;
    }
    return solution;
}
 
int main()
{
    cin >> n >> k;
 
    for(int i = 1 ; i <= n ; ++ i)
    {
        bool x;
        cin >> x;
        knowledge[i] = x;
    }
 
    cin >> m;
 
    for(int i = 1 ; i <= m ; ++ i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        G[a].push_back(mp(b, c, d));
        G[b].push_back(mp(a, c, d));
    }
 
    answer1 = bf(k);
    answer2 = bs();
    cout << answer1 << " " << answer2 << "\n";
    return 0;
}