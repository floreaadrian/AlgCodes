#include<fstream>
using namespace std;
long N,inceput,sfarsit,i,j,max,sum,v[7000011],poz,k;
int main() 
{ 
ifstream f("perle2.in"); 
f>>N>>k; 
for (i=1;i<=N;++i) 
f>>v[i];
int max=0,sum=0; 
for(i=1;i<=N;++i)
{
	v[i]=v[i]-k;
}
for (i=1;i<=N;i++) 
{ 
if (sum>=0) 
sum= sum + v[i]; 
else 
{ 
sum=v[i]; 
poz=i; 
} 
if (sum>max) 
{ 
max=sum; 
inceput=poz; 
sfarsit=i; 
} 
} 
ofstream g("perle2.out"); 
g<<max; 
return 0;
}
