#include <fstream>
 
using namespace std;
 
ifstream fin ("arbint.in");
ofstream fout ("arbint.out");
 
int n, m;
int arb[400005];
int x, a, b;
 
void add (int node, int left, int right)
{
    if (left == right)
    {
        arb[node]=x;
        return;
    }
    int mid=left-(left-right)/2;
    if (a<=mid)
        add(2*node,left,mid);
    else
        add (2*node+1,mid+1,right);
 
    arb[node]=max(arb[2*node+1],arb[2*node]);
}
 
void query (int node, int left, int right)
{
    if (a<=left && right<=b)
    {
        x=max(arb[node],x);
        return ;
    }
    int mid=(left-((left-right)/2));
    if (a<=mid)
        query(2*node,left,mid);
    if (mid<b)
        query(2*node+1,mid+1,right);
}
 
int main ()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    {
        a = i;
        fin >> x;
        add (1, 1, n);
    }
    for (int i = 0; i < m; ++i)
    {
        int k;
        fin >> k;
        if (k==1)
        {
            fin >> a >> x;
            add (1, 1, n);
        }
        else
        {
            x = -1;
            fin >> a >> b;
            query (1, 1, n);
            fout << x << "\n";
        }
    }
    fin.close();
    fout.close();
 
    return 0;
}
