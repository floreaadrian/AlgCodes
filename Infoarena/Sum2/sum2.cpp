#include<iostream>
#include<fstream>
#define N 100004

using namespace std;

ifstream in("sum2.in");
ofstream out("sum2.out");

int n,l,U,smax=-1000000,d[N],p=1,u,y[N];
short x[N];

inline void swap(int &a, int & b) {
 int t=a;
 a=b;
 b=t;
}

inline void add(const int &a) {
 d[++u]=a;
}

inline void stanga(int i) {
 if(p<=u && i - d[p]>= U)
  ++p;
}

inline void dreapta() {
 while(u!=p && y[d[u]] <= y[d[u-1]]) {
  swap(d[u],d[u-1]);
  --u;
 }
}

void so() {
 int i;
 
 for(i=0;i<U-l-1;++i) {
  add(i);
  dreapta();
 }
 
 for(i=U;i<=n;++i) {
  stanga(i);
  add(i-l-1);
  dreapta();
  if(y[i]-y[d[p]]>smax)
   smax=y[i]-y[d[p]];
 }
 add(i-l-1);
 dreapta();
 if(y[i-1]-y[d[p]]>smax)
  smax=y[i-1]-y[d[p]];
}

int main() {
 int i;
 in >> n >> l >> U;
 
 for(i=1;i<=n;++i) {
  in >> x[i];
  y[i]=x[i] + y[i-1];
 }
 so();
 
 out << smax;
 
 return 0;
}
