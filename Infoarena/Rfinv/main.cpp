#include <fstream>
#include <string.h>

using namespace std;

ifstream fin("rfinv.in");
ofstream fout("rfinv.out");

int a[55][55],b[55][55],n; //declaram n-numarul de noduri,a si b,matricile unde o sa salvam grafurile

bool verf(){ //verificare daca matricea initiala si matricea roy-floydului sters sunte egale
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j){
        if(a[i][j]!=b[i][j])return false; //matricile au un element diferit => nu sunt egale
    }
    return true; //matricile sunt egale
}

int main()
{
    int m,t;
    fin>>t; //citim numarul de teste
    while(t--){ //parcurgem testele
        fin>>n>>m; //citim numarul de noduri si numarul de muchii
        for(int i=1;i<=m;++i){ //parcurgem muchiile
            int x,y;
            fin>>x>>y; //citim nodurile x si y
            a[x][y]=a[y][x]=1; //distanta dintre nodul x si y este 1
        }
        for(int i=1;i<=n;++i) //citim matricea stearsa
        for(int j=1;j<=n;++j){
            fin>>b[i][j];
            if(a[i][j])a[i][j]=b[i][j]; //daca exista muchia intre i si j ii dam valoarea matricii sterse
        }
        int i,j,k;
        for(k=1;k<=n;k++) //parcurgem n posibile conexiuni,adica daca k este punct comun intre i si j
            for(i=1;i<=n;i++) //dintre nodul i
                for(j=1;j<=n;j++) //si nodul j
                    if(a[i][k] && a[k][j] && (a[i][j]>a[i][k]+a[k][j] || !a[i][j]) && i!=j) a[i][j]=a[i][k]+a[k][j]; //daca exista o conexiune
                    //intre nodul i si k si k si j,si daca distanta de la nodul i la k + distanta de la k la j este mai mica decat distanta
                    //directa,atunci distanta de la i la j este distanta intermediara
        if(verf())fout<<"DA\n"; //daca matricea stearsa este la fel cu cea creata afisam DA
            else fout<<"NU\n";//altfel afisam NU
        memset(b,0,sizeof(b)); //golom matricile
        memset(a,0,sizeof(a));
    }
    return 0;
}
