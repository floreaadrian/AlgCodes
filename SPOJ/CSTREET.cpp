#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <bitset>
#include <string.h>

using namespace std;
const int maxn = 200005;
vector <pair<int, pair<int, int> > > edges; //declaram si initializam un vector care contine o pereche intr-o pereche
int n, m, father[maxn],total; //declaram totalul,vectorul de tati, n si m

inline int find(int x) { // subprogram care cauta tatal unui nod
    if(father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}

inline bool unite(int x, int y) { //subprogram care uneste doua noduri si verifica daca ele au fost unite inainte
    x = find(x); //cauta tatal noduli x
    y = find(y); //cauta tatal noduli y
    if(x == y) //daca cele doua noduri au acelasi tata inseamna ca ele sunt unite
        return false; //daca sunt unite returnam fals
    father[x] = y; //tatal lui x este y
    return true; //returnam adevarat
}

inline void kruskal() {

    sort(edges.begin(), edges.end()); //sortam muchiile in functie de cost
    for(int i = 0 ; i < edges.size() ; ++ i) { //parcurgem fiecare muchie
        if(unite(edges[i].second.first, edges[i].second.second)) { //verificam daca primul element din a doua pereche cu al doilea element din acea pereche(adica nodul x,respectiv nodul y) sunt sau nu unite
            total += edges[i].first; //daca nu sunt unite aduma la costul total,costul actual
        }
    }
}

int main()
{
	int t,cost;
	cin>>t; //citim numarul de cazuri
	while(t--) //parcurgem cazurile
	{
		cin>>cost; //citim costul unei unitati de drum
		cin>>n; //citim numarul de orase
		cin>>m; //citim numarul de cai
		for(int i=0;i<m;i++){ //parcurgem fiecare cale
			int x,y,z;
			cin>>x>>y>>z; //citim nodul x si y si distanta dintre ele
			edges.push_back(make_pair(z,make_pair(x,y))); //creem o pereche in care primul element este costul si al doilea este alta pereche care contine primul si al doilea element
		}
		for(int i=1;i<=n;i++)
		      father[i]=i; //fiecare element se are tata pe el insusi initial
		total=0; //totalul este 0
		kruskal(); //aplicam algoritmul prinical
		cout<<total*cost<<"\n"; //afisam costul total
		edges.clear();//stergem fiecare muchie pentru urmatorul test
	}
	return 0;
}
