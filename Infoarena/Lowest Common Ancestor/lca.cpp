#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("lca.in");
ofstream fout("lca.out");

const int maxn = 100005;
const int maxlg = 25;

int n, m, first[maxn], euler[maxn << 1], rmq[maxlg][maxn << 1], lvl[maxn << 1], k, lg[maxn << 1];
vector <int> g[maxn];

inline void dfs(int node, int level) {
    first[node] = ++ k; //nodul actual este adaugat in reprezentarea Euler a arborelui
    euler[k] = node; //se retine nivelul fiecarei pozitii din reprezentarea Euler a arborelui
    lvl[k] = level; //se retine si prima aparitie a fiecarui nod in reprezentarea Euler a arborelui
    int nr=g[node].size(); //numarul de vecini al nodului node
    for(int i=0;i<nr;i++) { //parcurgem vecini
        dfs(g[node][i], level + 1); //parcurgem iara cu un nivel mai mare
        euler[++ k] = node; //crestem k si salvam nodul
        lvl[k] = level; //nivelul lui k este nivelul acutal
        //ultimele doua linii de cod se aplica dupa ce nu mai poate fi aplicat dfs
    }
}

inline int lca(int x, int y) {
    //LCA-ul nodurilor x si y va fi nodul cu nivel minim din secventa (First[x], First[y]) din reprezentarea Euler a arborelui
    x = first[x];//x este unde l-am gasit prima data
    y = first[y];//y este unde l-am gasit prima data
    if(x > y)
        swap(x, y);
    int l = lg[y - x + 1];
    int ret = rmq[l][x];//retinem unde l-am vazut
    if(lvl[ret] > lvl[rmq[l][y - (1 << l) + 1]]) //daca nivelul este mai mare decat nodul de nivel minim dintre pozitiile (j, j + 2^i - 1) din reprezentarea Euler a arborelui
        ret = rmq[l][y - (1 << l) + 1];
    return euler[ret]; //returnam nodul de stramosului
}

int main() {
    fin >> n >> m;
    for(int i = 2 ; i <= n ; ++ i) {
        int x;
        fin >> x;
        g[x].push_back(i);
    }
    dfs(1, 1);
    for(int i = 2 ; i <= k ; ++ i)
        lg[i] = lg[i >> 1] + 1;
    for(int i = 1 ; i <= k ; ++ i)
        rmq[0][i] = i; //nodul de nivel minim dintre pozitiile (j, j + 2^i - 1) din reprezentarea Euler a arborelui
    for(int l = 1 ; (1 << l) <= k ; ++ l) {
        int aux = (1 << (l - 1));
        for(int j = 1 ; j + (1 << l) - 1 <= k ; ++ j) {
            rmq[l][j] = rmq[l - 1][j];
            if(lvl[rmq[l][j]] > lvl[rmq[l - 1][j + aux]])
                rmq[l][j] = rmq[l - 1][j + aux];
        }
    }
    for(int i = 1 ; i <= m ; ++ i) {
        int x, y;
        fin >> x >> y;
        fout << lca(x, y) << '\n'; //afisam cel mai apropiat stramos comun al lui x si y
    }
}
