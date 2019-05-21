#include <iostream>

using namespace std;

#define mod 9

long long int power(long long int b, long long int e, long long int ans) {
    if (!e) return ans;
    if (e & 1) ans = (ans * b) % mod;
    return power((b * b) % mod, e >> 1, ans);
}

int main() {
    int t;
    cin >> t;
    long long int a, n;
    while (t--) {
        cin>>a>>n;
        a = a % mod;
        if (a == 0) a = 9;
        long long int rez = power(a, n, 1);
        rez = !rez ? 9 : rez;
        cout<<rez<<"\n";
    }
    return 0;
}
