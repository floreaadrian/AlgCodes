#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

int n, dp[255][255], xpaznic, ypaznic;

char s[255][255];

const int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
const int dy[] = {1, 0, 0,-1,-1, 1, -1, 1};

queue < pair<int, int> > q;

ifstream fin("muzeu.in");
ofstream fout("muzeu.out");

bool inside(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n; //verificam daca este inauntrul matricii
}

void lee() {
    while(!q.empty()) { //cat timp coada este goala
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; ++ i) {
            int newx = x + dx[i]; //facem ca noul x sa fie vechiul x + actuala coordonata a lui x(preluata din dx)
            int newy = y + dy[i]; //facem ca noul y sa fie vechiul y + actuala coordonata a lui y(preluata din dy)
            if(inside(newx, newy) && (dp[newx][newy] == -1 || dp[newx][newy] > dp[x][y] + 1)) {  //verificam daca este inauntru si daca este -1 sau daca locul nou exte mai mare decat cel vechi +1
                dp[newx][newy] = dp[x][y] + 1; //este atunci crestem locul nou cu 1
                q.push(make_pair(newx, newy)); // le bagam in coada
            }
        }
    }
    for(int i = 1 ; i <= n ; ++ i, fout << '\n')
    for(int j = 1 ; j <= n ; ++ j)
    fout << dp[i][j] << ' ';//afisam dp
}

int main ()
{
    fin >> n;//citim numarul de linii
    for(int i = 1 ; i <= n ; ++ i)
        for(int j = 1 ; j <= n ; ++ j) {
            fin >> s[i][j];
            if(s[i][j] == '#')
            dp[i][j] = -2; //camera inchisa
            else if(s[i][j] == '.')
            dp[i][j] = -1; //libera fara paznic
            else {
            q.push(make_pair(i, j)); //fiecare loc de pornire
            dp[i][j] = 0;
        }
    }
    lee();//facem lee pentru a incepe
}
