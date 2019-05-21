#include <iostream>

using namespace std;

int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   int rest=c-a;
   if((rest/b)%2==0)
    cout<<"Lucky Chef\n";
   else cout<<"Unlucky Chef\n";
    return 0;
}
