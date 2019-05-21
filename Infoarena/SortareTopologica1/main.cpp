#include <fstream>
#include <vector>

using namespace std;

ifstream fin("sortaret.in");
ofstream fout("sortaret.out");

vector <int> a[50001];//declaram vectorul in care salvam graful
vector <int> sta;//declaram vectorul unde salvam elementele sortarii in ordine
bool viz[50001]; //declaram un bool pentru a vedea daca un nod este vizitat sau nu
int n; //numarul de noduri

void df(int nod)
{
    viz[nod]=1; //nodul nod l-am vizitat
    for(auto it: a[nod]) //parcurgem vecinii nodului nod
        if(!viz[it]) //verificam daca vecinul nu este vizitat
        df(it);//daca nu este,il vizitam
    sta.push_back(nod); //dupa ce nu mai putem face dfs,toate nodurile au fost salvete in stiva si acum le introducem in vectorul sta
}

int main()
{
    int m;
    fin>>n>>m; //citim numarul de noduri si de muchii
    for(int i=1;i<=m;++i)
    {
        int x,y;
        fin>>x>>y; //citimi nodul x si nodul y
        a[x].push_back(y); //nodul y este vecin cu nodul x
    }
    for(int i=1;i<=n;++i) //parcurgem fiecare nod
        if(viz[i]==0) //verificam daca nu este vizitat
        df(i); //daca nu e vizitat,aplicam df pe el
    for(int i=sta.size()-1;i>=0;i--)//accesam in ordinea inverasa a salvarii,elementele sortarii
        fout<<sta[i]<<" ";//afisam elementul i
    return 0;
}
