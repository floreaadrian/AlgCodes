#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;

double V[3];
int main() {
    cin >> V[0] >> V[1] >> V[2];
        sort(V, V+3, greater<double>());

        if (V[0] > V[1] + V[2])
            cout << "NAO FORMA TRIANGULO\n";
        if (V[0]*V[0] == V[1]*V[1] + V[2]*V[2])
            cout << "TRIANGULO RETANGULO\n";
        if (V[0]*V[0] > V[1]*V[1] + V[2]*V[2])
            cout << "TRIANGULO OBTUSANGULO\n";
        if (V[0]*V[0] < V[1]*V[1] + V[2]*V[2])
            cout << "TRIANGULO ACUTANGULO\n";
        if (V[0] == V[1] && V[1] == V[2])
            cout << "TRIANGULO EQUILATERO\n";
        if (V[0] == V[1] ^ V[1] == V[2] ^ V[0] == V[2])
            cout << "TRIANGULO ISOSCELES\n";
}
