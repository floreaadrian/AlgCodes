#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#define maxn 7505

using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

vector <int> g[maxn], costX(maxn , 0), costY(maxn , 0); //declaram vectorul grafului,vectorul care contine costul de X si unu cu costul de Y
queue <int> q; //declaram coada q
bitset <maxn> a; //daclaram un bitset a in care vedem daca este vizitat un nod

int n,m,x,y,sol,val[maxn],cate[maxn]; //declarm valoarea pana la un nod si cate au ajuns

int main()
{
    fin>>n>>m>>x>>y;//citim numarul de noduri,cel de muchii,si nodul x si y
    for(int i=1;i<=m;++i){ //parcurgem fiecare muchie
        int c,d;
        fin>>c>>d; //citim nodul c si d
        g[c].push_back(d); //nodul d este vecin al nodului c
        g[d].push_back(c);//nodul c este vecin al nodului d
    }
    for(q.push(x),costX[x]=1;!q.empty();q.pop()){ //parcurgem coada cu de la nodul x,iar costul initial este 1
        int nod=q.front(); //nod este primul element din coada
        for(auto it: g[nod]) //parcurgem fiecare vecin al lui nod
        if(!costX[it]){ //vedem daca nu este vizitat(nu este vizitat doarece costul pana la el este 0)
            costX[it]=costX[nod]+1; //daca nu este vizitat nodul vecin,costul pana la el este costul care a fost pana la nod +1
            q.push(it); //bagam nodul vecin in coada
        }
    }
    int minim=costX[y]; //minimul este costul pana la nodul y avand punctul de plecare x
    //aici folosim acelasi algoritm ca si la x doar ca pornim de la y si verificam distanta pana la fiecare nod
    for(q.push(y),costY[y]=1;!q.empty();q.pop())
    {
        int nod=q.front();
        for(auto it: g[node])
            if(!costY[it])
            costY[it]=costY[nod]+1,q.push(it);
    }
    for(int i=1;i<=n;++i) //parcurgem fiecare nod
        if(costX[i]+costY[i]==minim+1){ //daca distanta de la x pana la i plus distanta de la y pana la i este distanta de la x la y +1
            cate[costX[i]]++; //spunem ca costul pana in nodul i a fost gasit
            val[costX[i]]=i; //valoarea costuli este nodul i
        }
    for(int i=1;i<=n;++i) //parcurgem fiecare nod
    if(cate[i]==1){ //daca costl a fost doar odata
        ++sol; //crestem numarul de solutii
        a[val[i]]=1; //spunem ca am ajuns in valoare costuli
    }
    fout<<sol<<"\n"; //afisam numarul de solutii
    for(int i=1;i<=n;++i) //parcurgem fiecare nod
        if(a[i]) //verificam daca face parte din lant
        fout<<i<<" "; //daca face parte il afisam
    return 0;
}
