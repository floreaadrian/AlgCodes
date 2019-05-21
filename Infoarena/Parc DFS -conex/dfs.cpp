#include<vector>
#include<fstream>
using namespace std;

int viz[100005],n,m,x,y,cnt=0;
vector <int> A[100001];
ifstream fin("dfs.in");
ofstream fout("dfs.out");

void citeste_graf() //functie in care citim datele
{
    int i;
    fin>>n>>m; //citim numarul de noduri si cel de muchii
    for(i=1;i<=m;i++)
    {
        fin>>x>>y; //citim nodul x si y
        A[x].push_back(y); //y este venic cu x
        A[y].push_back(x); //x este vecin cu y
    }
    fin.close();
}

void df(int nod)
{
    viz[nod]=1;//spunem ca am vizitat nodul nod
    for(auto it: A[nod]) //parcurgem vecinii nodului
        if(!viz[it]) //verificam daca nu este vizitat
        df(it); //daca nu este vizitat il accesam
}

int main()
{
    citeste_graf(); //citim datele
    for(int i=1;i<=n;i++) //parcurgem fiecare nod
    if(viz[i]==0) //verificam daca nu este vizitat
    {
        cnt++; //daca nu este vizitat inseamna ca nu a mai avut vre-o legatura cu al nod => avem o noau componenta conexa
        df(i); //alpicam algoritmul df asupra noduli i
    }
    fout<<cnt; //afisam numarul de componente conexe
    fout.close();
    return 0;
}
