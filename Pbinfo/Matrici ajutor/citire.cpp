#include <iosteram>

using namespace std;

int main()
{
    int n,m,a[100][100];
    /*
        n-numarul de lini
        m-numarul de coloane
        a[100][100]-matricea a care poate contine maxim 100 de lini si 100 de coloane
    */
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
            /*
            citim elementul de pe pozitia i si j, matricea noastra o sa aiba n lini si m coloane
            ocupate,nu dimensiunea care i-am dat-o la initializare
            */
    return 0;
}
