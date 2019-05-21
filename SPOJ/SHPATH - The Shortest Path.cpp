#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef vector<int> vi; //predefinim un vector<int> cu expresia vi
#define INF (1<<25) //predefinim INF cu valoarea 2^25, "<<" mutand toti biti lui 1 de 25 de ori la stanga

map<string,int> city; //definim o harta care sa ne retina numele orasuli alaturi de id-ul intreg al sau
vector <pair<int, int> > vecini[10005]; //vector care retine vecinii
vector <int> vals; //vectorul de costuri
int n; //numarul de orase

typedef bool (*comp)(pair<int,int> ,pair<int,int> ); // predefinim o structura bool

bool compare(pair<int,int> a,pair<int,int>  b){ //structura predefinita in care comparam valorile a doua perechi de int
	return a.second>b.second;
}

void dijkstras(int source,int destination){ //algoritmul principal
	priority_queue<pair<int,int> ,vector< pair<int,int> > ,comp> pq(compare); //definim o coada prioritara in care primul element este cel mai mare mereu
	pq.push(make_pair(source,0)); // introducem in coada sursa cu valoare drumului 0
	vals[source]=0; // spunem ca am vizitat sursa
	while(!pq.empty()){ //parcurgem coada pana este goala
		pair<int,int>  x = pq.top(); // declaram si initiem parechea de int x cu primul element din coada
		int top=x.first; // spuem ca elementul actual este primul element din perechea x
		pq.pop(); //scoatem perechea din coada
		if(top==destination)break; //daca am ajuns la destinatie iesim din subprogram
		if(vals[top]<x.second){
			continue;
		}
		for(auto it: vecini[top]){ //vizitam toti vecinii nodului actual
			pair<int,int>  vecin = it; //declaram perechea vecin cu nodul actual
			int in = vecin.first, cost = vecin.second; //in reprezinta numarul nodului si cost costul acestuia
			if(vals[in]>vals[top]+cost){ //daca costul pana la vecin e mai mare decat costul nodului actual + costul vecinului
				vals[in]=vals[top]+cost; //inlocuim acest cost
				pq.push(make_pair(in,vals[in])); //bagam in coada perechea formata din nodul vecin si costul pana aici
			}
		}
	}
}


int main(){
	int t;
	cin>>t; //citim numarul de teste
	city.clear();
	while(t--){ //parcurgem fiecare test
		cin>>n; //citim numarul de orase
		memset(vecini,0,sizeof(vecini)); //golim vectorul de vecini
		for(int i=0;i<n;++i){ //parcurgem fiecare oras
			char name[11];
			cin>>name; //citim numele orasuli
			city[string(name)]=i; //salvam numele orasuli in harta impreuna cu numarul de ordine
			int inn;
			cin>>inn; //citim numarul de vecini ai orasului
			while(inn--){
				int nr,cost;
				cin>>nr>>cost; //citim numarul de ordine al orasuli si costul de a ajunge la el
				vecini[i].push_back(make_pair(nr-1,cost)); //le bagam in vectorul vecini
			}
		}
		int r;
		cin>>r; //citim numarul de drumuri care trebuie aflate
		while(r--){ //
			char source[11],destination[11];
			cin>>source;cin>>destination; //citim sursa si destinatia
			vals = vi(n,INF);
			string start = string(source);
			string end = string(destination);
			dijkstras(city[start],city[end]); //aplicam algoritmul principal 
			cout<<vals[city[end]]<<"\n"; //afisam rezultatul
		}
	}
	return 0;
}
