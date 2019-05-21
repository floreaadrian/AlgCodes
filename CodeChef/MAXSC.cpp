//
// Created by Adrian-Paul Florea on 1/6/18.
//
#include<iostream>

using namespace std;

int main() {
    int t, k;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int a[705][705];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin>>a[i][j];
        long long int ctr = 0;
        int p = 1, c = 0, d = -1;
        while (p <= n) {
            long long int aux = -1;
            for (int j = 2; j <= n; j++) {
                if (a[p][j] > a[p][j - 1] && a[p][j] > aux)
                    aux = a[p][j];
            }
            if (aux != -1)
                ctr = ctr + aux;
            else {
                c = 1;
                p = n + 1;
            }
            p++;
        }
        if (c == 1)
            printf("%d\n", d);
        else
            printf("%lld\n", ctr);
    }
}

