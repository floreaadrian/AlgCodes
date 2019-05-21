#include<iostream>
#include<fstream>
using namespace std;
ofstream fout("scmax.out");
int v[100],n,p[100],d[100];
void citire()
{
 int i;
 ifstream f("scmax.in");
 f>>n;
 for(i=1;i<=n;i++){
 f>>v[i];
}
 f.close();
}
void afis(int k)
{
 while(k!=0){fout<<v[k]<<" ";
             k=p[k];}
}
int maxim(int i)
{
 int j,max=0,poz=-1;
 for(j=i+1;j<=n;j++)if(v[j]>v[i] && d[j]>max){max=d[j];poz=j;}
 return poz;
}
void dinamica()
{
 int i,poz,pozmax,maxp;
 d[n]=1;
 p[n]=0;pozmax=n;maxp=1;
 for(i=n-1;i>=1;i--){
                  poz=maxim(i);
                    if(poz==-1){d[i]=1;p[i]=0;}
        else {
          d[i]=1+d[poz];
       p[i]=poz;
       if(d[i]>maxp){maxp=d[i];pozmax=i;}
             }
                     }
 fout<<maxp<<"\n";
 afis(pozmax);
}
int main()
{
 citire();
 dinamica();
 return 0;
}
