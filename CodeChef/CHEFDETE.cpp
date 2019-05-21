#include <iostream>
#include <vector>

using namespace std;

bool graf[100001];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        graf[a]=true;
    }
    for(int i=1;i<=n;i++)
        if(graf[i]==false)
        cout<<i<<" ";
    return 0;
}
