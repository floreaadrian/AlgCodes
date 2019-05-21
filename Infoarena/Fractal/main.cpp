#include <fstream>

using namespace std;

ifstream fin("fractal.in");
ofstream fout("fractal.out");

int k,x,y;

int solve(int k, int x, int y)
{
    if(k==0) return 0;
    int mij=(1<<(k-1));
    int f=mij*mij;
    if(x<=mij && y<=mij) return solve(k-1,y,x);
    if(x<=mij && y>mij) return 3*f+solve(k-1,2*mij-y+1,mij-x+1);
    if(x>mij && y<=mij) return f+solve(k-1,x-mij,y);
    if(x>mij && y>mij) return 2*f+solve(k-1,x-mij,y-mij);

}
int main()
{
    fin>>k>>y>>x;
    fout<<solve(k,x,y)<<'\n';
    return 0;
}
