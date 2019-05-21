#include <iostream>
#include <math.h>

using namespace std;

// double f(double a,double eps,double xn){
//
//        if (fabs(1.0/2*(xn+a/xn)-xn)<eps) return xn;
//         else
//         return f(a,eps,1.0/2*(xn+a/xn));
// }
//
// double f(double n,double eps,double xn){
//     if(sqrt(6*(xn+1.0/(n*n)))-sqrt(6*xn)<eps)
//         return sqrt(6*(xn+1.0/(n*n)));
//     else return f(n+1,eps,xn+1.0/(n*n));
// }
// int sor(int n,int x[]){
//     for(int i=1;i<=n;++i)
//         for(int j=i+1;j<=n;++j)
//             if(x[i]%3==0 && x[j]%3==0){
//             if(x[i]<x[j]){
//         int aux=x[i];
//         x[i]=x[j];
//         x[j]=aux;
//     }}
// }
// int prim(int n,int i){
//     if(n%i==0) return 0;
//     else if(i*i>n) return 1;
//     else return prim(n,i+1);
// }
//x
// int ogl(int n,int o){
//     if(n==0) return o;
//     else ogl(n/10,o*10+n%10);
// }
//
// int det(int n,int nr,int pu,int c1,int c2)
// {
//     if (n==0) return nr;
//     if (n%10>=c1&&n%10<=c2) return det(n/10,nr+(n%10)*pu,pu*10,c1,c2);
//     else return det(n/10,nr,pu,c1,c2);
//
//    if(n==0) return nr/10;
//     else if(n%10>=c1 && n%10<=c2) det(n/10,(n%10)*pu+nr,pu*10,c1,c2);
//     else det(n/10,nr,pu,c1,c2);
// }
// int v[500][1500];
//
// int cre(int x,int y){
//     int k[15000]={0};
//     for(int i=x;i<=y;++i){
//         int s=1;
//         for(int kk=2;kk<=i/2;++kk)
//             if(i%kk==0) s+=kk;
//         //cout<<s<<" ";
//         s+=i;
//         k[i]=s;
//         v[s][0]++;
//         v[s][v[s][0]]=i;
//     }
//     for(int i=x;i<=y;++i){
//         //cout<<k[i]<<"\n";
//             int poz=k[i];
//         if(v[poz][0]>1){
//             for(int j=1;j<=v[poz][0];++j)
//                 cout<<v[poz][j]<<" ";
//         cout<<"\n";
//         v[poz][0]=0;
//         }
//     }
// }
//
// void formula(int n){
//     int s=0;
//     for(int i=1;i*i<=n;++i)
//         if(n%i==0)
//         s=s+i+n/i;
//     cout<<s;
// }
//
// int cautare(int x,int v[],int n){
//     for(int i=1;i<=n;++i)
//         if(v[i]==x) return i;
//     return -1;
// }
//
// int Bin(int st,int dr,int v[],int x,int n){
//     int mid=(st+dr)/2;
//     if(v[mid]<x) return Bin(mid+1,dr,v,x,n);
//     else if(v[mid]>x) return Bin(st,mid-1,v,x,n);
//     else if(v[mid]==x) return mid;
//     if(st>dr) return -1;
// }
//
// int putere(int n,int d){
//     int s=1;
//     for(int i=1;i<=d;++i)
//         s*=n;
//     return s;
// }
//
// int cit(int n,int m,int a[][500],int act){
//     if(act==n*m) return 0;
//     else {
//        if(act%m==0)
//         cin>>a[m/act-1][m];
//         else cin>>a[m/act][m%act];
//         cit(n,m,a,act+1);
//     }
// }
//
// void citire(int a[][500],int i,int j,int m){
//     if(i>0)
//         if(j==0) citire(a,i-1,m,m);
//     else{
//         cout<<"a["<<i<<"]["<<j<<"]=";cin>>a[i][j];
//         citire(a,i,j-1,m);
//     }
// }
//
//
// void cre(int n,int a[][500]){
//     int ap=1,nr1=1;
//     int i=1,j=1;
//     for(int i=1;i<=n;++i)
//         for(int j=1;j<=n;++j)
//         {
//         int k=0;
//         while(k<=ap){
//             int jj;
//             for(jj=j;jj<=;++jj){
//                 a[i][j]=nr1;
//                 k++;
//             }
//             if(jj==n && k<ap){
//                 j=1;
//                 i++;
//             }
//         }
//         ap+=2;
//         nr1++;
//         }
// }

int main()
{
    // int n,c1,c2,m;
    // cin>>n;
    // int a[500][500];
    // cre(n,a);
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=1;j<=n;++j)
    //         cout<<a[i][j]<<" ";
    //     cout<<"\n";
    // }
    //
    // cin>>n;
    // int d=2;
    // int s=1;
    // while(n>1)
    // {
    //     int p=0;
    //     while(n%d==0)
    //     {
    //     p=p+1;
    //     n=n/d;
    //     }
    //     s=s*(putere(d,p+1)-1)/(d-1);
    //     d++;
    // }
    // cout<<s<<endl;
   // cin>>x>>y;
    //cre(x,y);
   // cout<<det(n,0,10,c1,c2)<<endl;
    //cout<<ogl(n,0)<<" ";
    //cout<<prim(n,2);
    return 0;
}
