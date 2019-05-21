#include <fstream>
#include <iostream>
using namespace std;
#define lg 100005
int init[lg],t[4*lg+200],a,b,rez;
inline int max(int a,int b)
 {
 return a>b?a:b;}

void construiesc(int st,int dr,int poz)
{
      if (st==dr)
        {init[st]=poz;
        return ;
        }
         
      int x=(st+dr)/2;
      construiesc(st,x,2*poz);
      construiesc(x+1,dr,2*poz+1);
      }

void actualizare(int poz,int val)
{
     int x=init[poz];
     t[x]=val;
     x>>=1;
     while(x)
     {t[x]=t[x]+val;
      x>>=1;
}
}
 
 
void actualizare2(int poz,int val)
{
     int x=init[poz];
     t[x]=t[x]-val;
    x>>=1;
     while(x)
     {t[x]=t[x]-val;
      x>>=1;
}
}
//***************INTEROGARE
void interogare(int st,int dr,int poz)
{
     if (st>b||dr<a) return;
     if (a<=st&&dr<=b)
               rez=rez+t[poz];
          else
          if (st<dr)
               {int x=(st+dr)/2;
                 interogare(st,x,poz*2);
                 interogare(x+1,dr,poz*2+1);
                 }
}
 
int main()
{int i,x,n,m;
     ifstream f("datorii.in");
     ofstream g("datorii.out");
     f>>n>>m;
    
    
     construiesc(1,n,1);
      
      
     for(i=1;i<=n;i=i+1)
      {f>>x;
        actualizare(i,x);
        }
    
for(i=1;i<=m;i++)
 {
                   f>>x>>a>>b;
                   if (x==1)  
                   {rez=0;
                    interogare(1,n,1);
                    g<<rez<<"\n";
                    }
                     
                    else
                    if (x==0)
                       actualizare2(a,b);
}
f.close();
g.close();
return 0;
}

