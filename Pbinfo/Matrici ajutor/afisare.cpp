#include <iosteram>

using namespace std;

int main()
{
    int n,m,a[100][100];
    //citirea
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    //afisarea
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            cout<<a[i][j]<<" ";//afisam fiecare element de pe linia i parcungand fiecare coloana
        cout<<"\n";//dupa fiecare linie mergem pe un rand nou
    }
    return 0;
}
