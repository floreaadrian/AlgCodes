#include <iostream>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    long long x, y, z;
    cin >> x >> y >> z;
    long long ans=0;
    if (x*2 + y > a) ans += (x*2 + y)  - a;
    if (z*3 + y > b) ans += (z*3 + y)  - b;
    cout<<ans;

    return 0;
}