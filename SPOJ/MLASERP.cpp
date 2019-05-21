#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;
const int MAX = 128;
bool inside(int a,int b,int c) { return a<=b && b<=c; }

char grid[MAX][MAX];
int d[MAX][MAX];
int R, C, sr, sc, er, ec;
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

bool valid(int r, int c) {
	return (inside(0, r, R-1) && inside(0, c, C-1));
}

int bfs() {
	int r1, c1, r2, c2, i, dir;
	queue< int > Q;
	memset(d, 0x3f, sizeof(d));
	d[sr][sc] = -1;
	Q.push(sr); Q.push(sc);
	while(!Q.empty()) {
		r1 = Q.front(); Q.pop();
		c1 = Q.front(); Q.pop();
		for(i = 0; i < 4; i++) {
			r2 = r1 + dr[i];
			c2 = c1 + dc[i];
			while(valid(r2, c2) && grid[r2][c2] != '*') {
				if(d[r2][c2] > d[r1][c1] + 1) {
					d[r2][c2] = d[r1][c1] + 1;
					if(r2==er && c2==ec) return d[r2][c2];
					Q.push(r2); Q.push(c2);
				}
				r2 += dr[i];
				c2 += dc[i];
			}
		}
	}
	return d[er][ec];
}

int main() {
	int i, j, cnt = 0;
	cin>>C>>R;
	for(i = 0; i < R; i++) {
		cin>>grid[i];
		for(j = 0; j < C && cnt < 2; j++) {
			if(grid[i][j]=='C') {
				if(cnt==0) {
				sr = i; sc = j; cnt++;}
				else {
				er = i; ec = j; cnt++;}
			}
		}
	}
	cout<<bfs();
	return 0;
}
