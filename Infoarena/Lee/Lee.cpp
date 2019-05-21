#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
int n, dp[255][255], xpaznic, ypaznic;
char s[255][255];
const int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
const int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
queue<pair<int, int>> q;
ifstream fin("muzeu.in");
ofstream fout("muzeu.out");
bool inside(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= n; }
void lee() {
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int newx = x + dx[i];
      int newy = y + dy[i];
      if (inside(newx, newy) &&
          (dp[newx][newy] == -1 || dp[newx][newy] > dp[x][y] + 1)) {
        dp[newx][newy] = dp[x][y] + 1;
        q.push(make_pair(newx, newy));
      }
    }
  }
  for (int i = 1; i <= n; ++i, fout << '\n')
    for (int j = 1; j <= n; ++j)
      fout << dp[i][j] << ' ';
}
int main() {
  fin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      fin >> s[i][j];
      if (s[i][j] == '#')
        dp[i][j] = -2;
      else if (s[i][j] == '.')
        dp[i][j] = -1;
      else {
        q.push(make_pair(i, j));
        dp[i][j] = 0;
      }
    }
  lee();
}
