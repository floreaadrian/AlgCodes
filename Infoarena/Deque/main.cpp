#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>

using namespace std;

const char infile[] = "deque.in";
const char outfile[] = "deque.out";

ifstream fin(infile);
ofstream fout(outfile);

const int MAXN = 5000005;
const int oo = 0x3f3f3f3f;

typedef vector<int> Graph[MAXN];
typedef vector<int> :: iterator It;

const inline int min(const int &a, const int &b) { if( a > b ) return b;   return a; }
const inline int max(const int &a, const int &b) { if( a < b ) return b;   return a; }
const inline void Get_min(int &a, const int b)    { if( a > b ) a = b; }
const inline void Get_max(int &a, const int b)    { if( a < b ) a = b; }

int K, N, a[MAXN];
long long S; /// bad appreciation
deque <int> dq;

int main() {
    fin >> N >> K;
    for(int i = 1 ; i <= N ; ++ i) {
        fin >> a[i];
        while(!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);
        if(i - dq.front() == K)
            dq.pop_front();
        if(i >= K)
            S += a[dq.front()];
    }
    fout << S << '\n';
    fin.close();
    fout.close();
    return 0;
}
