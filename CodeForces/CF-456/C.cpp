#include<iostream>

using namespace std;
#define ll long long int

int main() {
    int n,m;
    cin >> n >> m;
    ll a[n][n];
    ll b[n];
    int k = 0, no = 0, l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        sort(a[i], a[i] + n);
    for (int j = n - 2; j >= 0; j--) {
        for (l = 0; l < n; l++) {
            if (a[j][l] < a[n - 1][n - 1]) {
                b[k] = a[j][l];
            }
        }
        k++;
    }
    ll siz = n-1;

    if (siz == n - 1) {
        b[n - 1] = a[n - 1][n - 1];
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans = ans + b[i];
        cout << ans << endl;
    } else
        cout << "-1" << endl;
    return 0;
}
