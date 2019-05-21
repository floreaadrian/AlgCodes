#include <cstdio>
#include <algorithm>

using namespace std;

const int oo = 2e9;

int tata[15003], cost[15003], max_depth[15003], edge[30003], node1[30003], node2[30003], c[30003];

inline bool compare (const int &a, const int &b) {

    return c[a] < c[b];

}

inline int root (int node) {

    for (; tata[node] != node; node = tata[node]);
    return node;

}

inline void unite (const int &root, const int &_root, const int &a_cost) {

    if (max_depth[root] < max_depth[_root])
        tata[root] = _root,
        cost[root] = a_cost;
    else
        tata[_root] = root,
        cost[_root] = a_cost;
    if (max_depth[root] == max_depth[_root])
        ++max_depth[root];

}

int main () {

    freopen ("radiatie.in", "r", stdin);
    freopen ("radiatie.out", "w", stdout);
    int N, M, K, i, x, y, _lca, R;
    scanf ("%d%d%d", &N, &M, &K);
    for (i = 1; i <= N; ++i)
        tata[i] = i;
    for (i = 1; i <= M; ++i)
        scanf ("%d%d%d", node1 + i, node2 + i, c + i),
        edge[i] = i;
    sort (edge + 1, edge + M + 1, compare);
    for (i = 1; i <= M; ++i) {
        x = root (node1[edge[i]]);
        y = root (node2[edge[i]]);
        if (x != y)
            unite (x, y, c[edge[i]]);
    }
    while (K--) {
        scanf ("%d%d", &x, &y);
        R = 0;
        while (x != y)
            if (max_depth[x] < max_depth[y])
                R = max (R, cost[x]),
                x = tata[x];
            else
                R = max (R, cost[y]),
                y = tata[y];
        printf ("%d\n", R);
    }
    return 0;
}
