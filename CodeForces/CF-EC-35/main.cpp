#include <iostream>
#include <string.h>

using namespace std;
int perm[1501], bit[1501];

void swap(int l, int r) {
    while (l < r) {
        perm[l] = perm[l] ^ perm[r];
        perm[r] = perm[l] ^ perm[r];
        perm[l] = perm[l] ^ perm[r];
        l++;
        r--;
    }
}

void nou(int val, int place) {
    while (place < 1501) {
        bit[place] += val;
        place += place & (-place);
    }
}

int stiva(int place) {
    int rv = 0;
    while (place > 0) {
        rv += bit[place];
        place -= place & (-place);
    }
    return rv;
}

int main() {
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> perm[i];
    cin >> m;
    while (m--) {
        int l, r, ans = 0;
        memset(bit, 0, sizeof(bit));
        cin >> l >> r;
        swap(l, r);
        for (int i = n; i > 0; i--) {
            nou(1, perm[i]);
            ans += stiva(perm[i] - 1);
        }
        if (ans % 2 == 0)
            cout << "even\n";
        else cout << "odd\n";
    }
    return 0;
}