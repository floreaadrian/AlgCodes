#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#define oo 0x3f3f3f3f

using namespace std;

ifstream fin("harta.in");
ofstream fout("harta.out");

const int MAXN = 206;

typedef vector<int> Graph[MAXN]; //predefinim in Graph un vector int cu marimea MAXN
typedef vector<int> :: iterator It; //predefinim un iterator

int N, M, X, Y, C[MAXN][MAXN], F[MAXN][MAXN], Father[MAXN], maxFlow; // declaram tabelele de flux,fluxul maxim si vectorul de tati
Graph G; //declaram graful
bitset <MAXN> Used; //declaram un bitset unde vedem daca am vazut un nod
queue<int>Q; //declaram o coada

inline bool BFs() {
    Used.reset(); //restem bitestul de folisinta
    for(Q.push(0), Used[0] = true ; !Q.empty() ; Q.pop()){ //parcrugem coada
        int Node = Q.front(); //declaram in Node primul element din coada
        for(It it = G[Node].begin(), fin = G[Node].end(); it != fin ; ++ it) //parcurgem vecini cozii
            if(!Used[*it] && C[Node][*it] > F[Node][*it]) //verificam daca nu este vazut si daca flowul din f este mai mic decat cel din C
                Q.push(*it), Used[*it] = true, Father[*it] = Node; //daca conditiile au fost indeplinite spunem ca vecinul este vizitat si ca tatal vecinului este nodul
    }
    return Used[M]; //verificam daca nodul M a fost vizitat
}

int main() {
    fin >> N; //numaram numarul de noduri
    M = 2 * N + 1; //M este un numar care ne ajuta in a memora mai usor fluxul
    for(int i = 1 ; i <= N ; ++ i) { //mergem la fiecare nod
        int x, y;
        fin >> x >> y; X += x; Y += y; //citim cate drumuri intra si cate drumuri pornesc din nodul i
        G[0].push_back(i); //spunem ca 0 este vecin cu i
        C[0][i] = x; //cat ajunge in i este x
        G[i+N].push_back(M); //spunem ca i+N este vecin cu M
        C[i+N][M] = y; //cate ies din i
    }
    for(int i = 1 ; i <= N ; ++ i) //parcurgem fiecare nod pentru a vedea intrarea
        for(int j = N + 1 ; j < M ; ++ j) //parcurgem de la N+1 pana la M
            if(i != j - N) { //daca nu suntem in aceasi nod,deoarece nu punem intre acleasi noduri vecin
                C[i][j] = 1; //fluxul este 1
                G[i].push_back(j); //i este vecin cu j
                G[j].push_back(i); //j este vecin cu i
            }
    for( ; BFs() ; ) { //cat timp nu am ajuns la ultimul flux
        ++ maxFlow; //crestem fluxul
        for(int i = M ; i ; i = Father[i]) //parcurgem prin tati
            ++ F[Father[i]][i], //crestem fluxul care il avem de la tata pana la fiu
            -- F[i][Father[i]]; //scadem fluxul care il avem de la fiu pana la tata
    }
    fout << maxFlow << '\n'; //afisam fluxul
    for(int i = 1 ; i <= N ; ++ i) //parcurgem fiecare nod
        for(int j = N + 1; j < M ; ++ j)
            if(F[i][j] == 1) //daca am face parte din flux
                fout << i << ' ' << j - N  << '\n'; //afisam
    fin.close();
    fout.close();
    return 0;
}
