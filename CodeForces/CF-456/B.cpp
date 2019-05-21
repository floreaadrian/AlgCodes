//
// Created by Adrian-Paul Florea on 1/5/18.
//

#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll n, k, i, rez;
    cin >> n >> k;
    i = 0;
    while ((ll(1) << i) <= n) {
        ++i;
    }
    --i;
    rez = ll(1) << i;
    --i;
    --k;
    while (i >= 0) {
        if ((k > 0) || (((ll(1) << i) ^ rez) <= n)) {
            rez ^= (ll(1) << i);
        }
        --i;
    }
    cout << rez;
}