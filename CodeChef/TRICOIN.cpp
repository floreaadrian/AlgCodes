#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double h = sqrt((2*n)-1);
        long long t = h;
        long long temp = t*(t+1)/2;
        if(temp>n)
            cout<<(long long)h-1<<"\n";
        else cout<<(long long)h<<"\n";
    }
    return 0;
}
