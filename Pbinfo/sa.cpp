#include <iostream>
using namespace std;
int inceput[100], sfarsit[100], nr[100];
int main()
{int n, i, h, m, schimb, ultim, aux;
cin >> n;
for (i=0; i<n; i++) 
{nr[i]=i+1;
 cin>>h>>m; inceput[i]=h*60+m;
 cin>>h>>m; sfarsit[i]=h*60+m;}
do
 {schimb=0;
 for (i=0; i<n-1; i++)
 if (sfarsit[nr[i]]>sfarsit[nr[i+1]])
 {aux=nr[i];nr[i]=nr[i+1];nr[i+1]=aux; schimb=1;}
 }
while (schimb);
int k=0;
for (ultim=0, i=1; i<n; i++)
 if (inceput[nr[i]]>=sfarsit[nr[ultim]])
 {k++; ultim=i;}
 
 cout<<endl;
 return 0;}
