#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

int main()
{
    priority_queue <int> q;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        q.push(a);
    }
    if(n%2==0)
    {
        for(int i=1;i<(n/2);i++)
            q.pop();
        double a=q.top();
        q.pop();
        double b=q.top();
        cout<<fixed<<setprecision(1)<<(b/2+a/2);
    }else
    {
        for(int i=1;i<(n/2)+1;i++)
        q.pop();
        cout<<q.top();
    }
    return 0;
}
