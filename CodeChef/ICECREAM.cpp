#include <iostream>
#include <iomanip>
#define pi 3.14159265358979323846
using namespace std;

int main()
{
    double r1,r2,h1,h2;
    int t;
    cin>>t;
    while(t--){
        cin>>r1>>h1>>r2>>h2;
        double con=pi*r1*r1*h1/3,sfera=(4*pi*r1*r1*r1/3)/2;
        double suma=con+sfera,cilindru=pi*r2*r2*h2;
        cout<<fixed<<setprecision(7)<<suma<<" "<<cilindru<<"\n";
    }
    return 0;
}
