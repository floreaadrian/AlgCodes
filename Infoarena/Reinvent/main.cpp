#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int N, M, X, src[100005], dist[100005];
vector<int> G[100005];
queue<int> Q;

int main(void) {
  int i, j, n;

  freopen("reinvent.in", "r", stdin);
  freopen("reinvent.out", "w", stdout);

  scanf("%d %d %d", &N, &M, &X);
  for (; M; --M) {
    scanf("%d %d", &i, &j);
    G[i].push_back(j);
    G[j].push_back(i);
  }
  memset(src, -1, sizeof(src));
  for (; X; --X) {
    scanf("%d", &n);
    Q.push(n);
    src[n] = n;
  }

  while (!Q.empty()) {
    n = Q.front();
    Q.pop();
    for (vector<int>::iterator it = G[n].begin(); it != G[n].end(); ++it)
      if (src[*it] == -1) {
        Q.push(*it);
        src[*it] = src[n];
        dist[*it] = dist[n]+1;
      } else if (src[*it] != src[n]) {
        printf("%d\n", dist[*it]+dist[n]+1);
        return 0;
      }
  }

  return 0;
}
