#include <iostream>
using namespace std;
int ar[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47},n,m;

int main()
{
    cin >> n >> m;
    for(int i=0;i<15;i++)
        if(ar[i] == n && ar[i+1] == m)
        {
            cout << "YES";
            return 0;
        }
    cout << "NO";
    return 0;
}
