#include<fstream>

using namespace std;

ifstream fin("mincinosi.in");
ofstream fout("mincinosi.out");

int nrraspuns[1000005];

int main()
{   int i, n, max1=0,raspunsul=0, raspuns[1000005];

    fin>>n;
    for(i=1;i<=n;i++)
   {fin>>raspuns[i];
    nrraspuns[raspuns[i]]++;}
    for(i=0;i<=n;i++)
      if(i+nrraspuns[i]==n)
        if (max1<nrraspuns[i])
        {max1=nrraspuns[i];
         raspunsul=i;}
    fout<<max1<<"\n";
    for(i=0;i<=n;i++)
       if (raspuns[i]==raspunsul)
             fout<<i<<"\n";
    return 0;
}
