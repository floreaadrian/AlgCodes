#include <fstream>
#include <vector>
#include <queue>
#define oo 0x3f3f3f3f //definim oo cu o valoare foarte mare

using namespace std;

ifstream cin("bellmanford.in");
ofstream cout("bellmanford.out");

vector <pair <int,int> > G[50001]; //declaram graful
int D[50001],nr[500001]; //declaram distata pana la nod si nr de cate ori am ajuns pana la el
bool V[50001];

int main()
{
    int N,m;
    cin>>N>>m;//citim numarul de noduri si numarul de muchii
    for(int i=1;i<=m;++i){
        int x,y,z;
        cin>>x>>y>>z; //citim nodul x si y si costul drumului
        G[x].push_back(make_pair(y,z)); //nodul y este vecin a lui x iar distanta intre ele este z
    }
    for(int i=0;i<=N;i++) //pentru fiecare nod
        {D[i]=oo;V[i]=false;} //distanta pana la el este oo
            //p[i] este 0 si spunem ca nu am vizitat elementul
    V[1]=true;D[1]=0;// nodul 1 este vizitat si distanta de la el pana la el este 0
    queue<int>Q; //declaram o coada
    Q.push(1);//introducem in coada primul nod,1
    while(!Q.empty()) //cat timp mai avem elemente in coada
    {
        int nod=Q.front(); //primul element din coada este nodul nostru
        V[nod]=false; //spunem ca nu am vizitat nodul
        for(auto it: G[nod])//mergem la fiecare nod
        if (D[nod]+it.second<D[it.first]) //daca distanga pana la un nod vecin este mai mare decat dinstanta pana la nod +distanta de la nod pana la nodul vecin
        {
            D[it.first]=D[nod]+it.second; //distanta pana la noul vecin este distanta pana la nod + distanta de la nod pana la nodul vecin
            if(!V[it.first]) //daca nodul nu a fost vizitat
            {
                if(nr[it.first]>N) //verifiam daca este mai mare decat numarul de nodur
                {
                    cout<<"Ciclu negativ!\n"; //daca este inseamna ca este un ciclu negativ si spunem asta
                    return 0;//iesim din program
                }
                Q.push(it.first); //daca nu este ciclu negativ bagam in coada vecinul nodului node
                V[it.first]=true; //spunem ca l-am vizitat
                ++nr[it.first]; //marim de cate ori am ajuns la nodul asta
            }
        }
        Q.pop();//scoatem elementul din coada
    }
    for(int i=2;i<=N;i++) //parcurgem fiecare nod de la 2 la n
        cout<<D[i]<<" "; //afisam distanta de la nodul 1 pana la el
    return 0;
}
