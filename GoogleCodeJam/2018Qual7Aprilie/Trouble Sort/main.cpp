#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  long long n, t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cin >> n;
    vector<long long> even, odd, v, all;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      all.push_back(x);
      if (i % 2 == 0)
        even.push_back(x);
      else
        odd.push_back(x);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    sort(all.begin(), all.end());

    for (long long i = 0; i < even.size(); i++) {
      v.push_back(even[i]);
      if (i < odd.size())
        v.push_back(odd[i]);
    }

    bool sachin = false;
    for (long long i = 0; i < v.size(); i++) {
      if (v[i] != all[i]) {
        sachin = true;
        printf("Case #%d: %lld\n", tt, i);
        break;
      }
    }
    if (!sachin)
      printf("Case #%d: OK\n", tt);
  }
  return 0;
}
