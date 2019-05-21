#include <iostream>

using namespace std;

bool find(char c) {
    char verf[] = {'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'};
    for (int i = 0; i < 10; i++)
        if (verf[i] == c)
            return true;
    return false;
}

int main() {
    string c;
    cin >> c;
    int n = c.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
        if (find(c[i])==true)
            ans++;
    }
    cout << ans;
    return 0;
}