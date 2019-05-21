#include<iostream>
using namespace std;



int main() {
    int n;
    cin >> n;
    int f[26] = { 0 }; char e = '.';
    bool ok = false;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char c;
        string s;
        cin >> c >> s;
        if (c == '.') {
            if (ok)
                continue;
            for (int j = 0; j < s.size(); j++)
                f[s[i] - 'a'] = -1;
        }
        else if (c == '!') {
            if (ok) {
                ans++; continue;
            }
            for (int j = 0; j < s.size(); j++)
                if (f[s[i] - 'a'] != -1) {
                    f[s[i] - 'a']++;
                }
            int cnt = 0;
            for (int j = 0; j < 26; j++){
                if (f[j] > 0) {
                    e = s[i]; cnt++;
                }}
            if (cnt == 1)
                ok = true;
        }
        else {
            if (ok) {
                if (s[0] == e)
                    ans++;
            }
        }

    }cout << ans;

    return 0;
}