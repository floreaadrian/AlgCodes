#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

#define x first
#define y second

typedef pair<double, double> Point;

const int MAX_N = 120005;
const double EPS = 1e-12;

ifstream fin("infasuratoare.in");
ofstream fout("infasuratoare.out");

int n;
Point v[MAX_N],g[MAX_N];
bool vis[MAX_N];
int st[MAX_N], head;

void read() {
    fin >> n;
    for (int i = 1; i <= n; ++i)
        {fin >> v[i].x >> v[i].y;
        g[i].x=v[i].x;g[i].y=v[i].y;
        }
}

double cross_product(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (B.x - O.x) * (A.y - O.y);
}

void convex_hull() {
    sort(v + 1, v + n + 1);

    st[1] = 1; st[2] = 2; head = 2;
    vis[2] = true;

    for (int i = 1 ; i <= n; i ++ ) {
        if (vis[i]) continue;
        while (head >= 2 && cross_product(v[st[head - 1]], v[st[head]], v[i]) < EPS)
            vis[st[head--]] = false;
        st[++head] = i;
        vis[i] = true;
    }

    for (int i = n ; i >= 1; i -- ) {
        if (vis[i]) continue;
        while (head >= 2 && cross_product(v[st[head - 1]], v[st[head]], v[i]) < EPS)
            vis[st[head--]] = false;
        st[++head] = i;
        vis[i] = true;
    }
    fout << head - 1 << "\n";
    fout << setprecision(6) << fixed;
    for (int i = head-1 ; i >= 0; i--)
        for(int j = 1;j <= n ; ++j)
        if(v[st[i]].x==g[j].x && v[st[i]].y==g[j].y)
            fout<<j<<" ";
}

int main() {
    read();
    convex_hull();
}
