#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int shield;
    cin >> shield;
    string atack;
    cin >> atack;
    long long now = 1;
    long long hei = 0;
    for (int i = 0; i < atack.length(); ++i) {
      if (atack[i] == 'C')
        now *= 2;
      else
        hei += now;
    }
    if (hei <= shield) {
      printf("Case #%d: 0\n", t);
    } else {
      long long newAtack = 0;
      int pasi = 0;
      while (true) {
        long long cur = 1;
        newAtack = 0;
        for (int i = 0; i < atack.length(); ++i) {
          if (atack[i] == 'C')
            cur *= 2;
          else
            newAtack += cur;
        }
        if (newAtack <= shield)
          break;
        ++pasi;
        long long last = -1;
        for (int i = 0; i + 1 < atack.length(); ++i)
          if (atack[i] == 'C' && atack[i + 1] == 'S')
            last = i;
        if (last >= 0)
          swap(atack[last], atack[last + 1]);
        else
          break;
      }
      if (newAtack <= shield)
        printf("Case #%d: %d\n", tt, pasi);
      else
        printf("Case #%d: IMPOSSIBLE\n", tt);
    }
  }
  return 0;
}
