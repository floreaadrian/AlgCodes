#include <fstream>
using namespace std;
ifstream fin("reactivi.in");
ofstream fout("reactivi.out");
int N;
int ti[8000], tf[8000];
int main ()
{int nf, poz, miny, maxx, max, i, j, icx, icy;
 fin>>N;
 for (i=0;i<N;i++) fin>>ti[i]>>tf[i];
 fin.close();
 for (i=N-1; i>0; i--)
 {for (poz=i, j=0; j<i; j++)
 if (ti[j]>ti[poz] || ti[j]==ti[poz] && tf[j]<tf[poz]) poz=j;
 max=ti[poz];ti[poz]=ti[i]; ti[i]=max;
 max=tf[poz];tf[poz]=tf[i]; tf[i]=max; }
 nf=1; icx=ti[0];icy=tf[0];
 for (i=1; i<N; i++)
 {
 miny=icy;if (miny>tf[i]) miny=tf[i];
 maxx=icx;if (maxx<ti[i]) maxx=ti[i];
 if (maxx <= miny)
 {icx=maxx;icy=miny;}
 else
 {nf++;
 icx=ti[i];icy=tf[i]; }
 }
 fout<<nf<<'\n';
 fout.close(); return 0;} 
