#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = 2000005;

string a,b;
int nr, V[2000010], Sol[1010];

void Prefix()
{
    int k = 0;
    for (int i = 1; i < a.size(); i ++)
    {
        while (k && a[i] != a[k]) k = V[k - 1];
        if (a[i] == a[k]) k ++;
        V[i] = k;
    }
}

void KMP()
{
    Prefix();
    int k = 0;
    for (int i = 0; i < b.size(); i ++)
    {
        while (k && b[i] != a[k]) k = V[k - 1];
        if (b[i] == a[k]) k ++;
        if (k == a.size())
        {
            k = V[k - 1];
            if (++Sol[0] <= 1000) Sol[Sol[0]] = i - a.size() + 1;
        }
    }
}

int main() {
    int la,ma;
    string ar1;
    cin>>la>>ma;
    int n=0,m=0;
    for(int i=1;i<=la;++i){
        cin>>ar1;
        for(int s=1;s<=ar1[0]-48;s++)
        {
           // cout<<ar1[2]<<" ";
            b[m]=ar1[2];
            cout<<b[m]<<" ";
            m++;
        }
    }
    for(int i=1;i<=ma;++i){
        cin>>ar1;
        for(int s=1;s<=ar1[0]-48;s++)
        {
            a[n]=ar1[2];
            n++;
        }
    }
    cout<<;
    //cout<<A<<"\n"<<B;
//    a=A;b=B;
    KMP();
    cout << Sol[0] << '\n';
}
