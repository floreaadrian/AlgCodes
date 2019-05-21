#include <fstream>
#include <vector>

using namespace std;

ifstream fin("ciclueuler.in");
ofstream fout("ciclueuler.out");

vector <int> G[100010]; //declaram graful
int d[100010], n, st[100010 * 5], viz[100010]; //declaram n,vectorul de vizite,vectorul de intrari si simularea de coada

void df(int nod)
{
    viz[nod] = 1; //nodul actual este vizitat
    for(auto it: G[node]) //parcurgem fiecare vecin al noduli nod
        if(!viz[it]) //verificam daca a mai fost vizitat
            df(it); //daca nu a mai fost vizitat il vizitam
}

bool ok()
{
    for(int i = 1 ; i <= n ; i++) //parcurgem fiecare nod
        if(!viz[i] || d[i] % 2) //vedem daca este sau nu vizitat si daca numarul de intrari este par
            return false; //daca conditiile nu au fost indeplinite inseamna ca nu este ciclu eularian si returnam fals
    return true;
}

int main()
{
    int m, x, y, dr = 0, nod, v;
    fin >> n >> m; //citim numarul de noduri si muchii
    while(m--) //parcurgem muchiile
    {
        fin >> x >> y;//citim nodul x si y
        G[x].push_back(y); //x este vecin cu y
        G[y].push_back(x); //y este vecin cu x
        d[x]++;d[y]++;//salvam de cate ori s-a intrat in x si y
    }
    df(1); //parcurgem o data graful
    if(!ok()) //verificam daca este sau nu ciclu eularian
    {
        fout << "Nu este ciclu eularian\n"; //daca nu este afisam
        return 0; //iesim din program
    }
    st[++dr] = 1; //elementul de start este 1
    //in st simulam o coada
    while(dr)
    {
        nod = st[dr]; //nodul este primul element din start
        if(G[nod].size()) //verificam daca acest nod mai are vecini
        {
            v = G[nod][0]; //nodul v este primul vecin a lui n
            G[nod].erase(G[nod].begin()); //stergem nodul v din lista de vecini a lui nod
            for(vector <int> :: iterator it = G[v].begin() ; it != G[v].end() ; it++) //parcurgem lista de vecini a lui v sa il stergem si pe nod din lista de vecini a lui v
                if(*it == nod) //verificam daca l-am gasit
                {
                    G[v].erase(it); //stegem nodul nod din lista de vecini a lui v
                    break; //nu mai trebuie sa cautam
                }
            st[++dr] = v; //adaugam nodul pentru ciclu
            continue; //operatia de citire inca nu se afiseaza
        }
        if(dr-1) //daca nu am terminat
            fout << nod << " "; //afisam nodul curent
        dr--; //scadem numarul de noduri care trebuie afisate
    }
    return 0;
}
