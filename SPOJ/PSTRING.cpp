#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>	
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;


const double EPS = 1e-10;
const int INF = 0x3f3f3f3f;

const int XLEN = 10001, YLEN = 1001, MC = 256;
char X[XLEN], Y[YLEN];
int F[YLEN], prec[YLEN][MC], dp[YLEN], cp[YLEN];
bool P[MC];

int main() {
	int i, j, k, xlen, ylen, tmp;
	while(cin>>X>>Y) {
		xlen = strlen(X), ylen = strlen(Y);
		memset(F,0,sizeof(F));
    	for(i=2; i<ylen; i++) {
			for(j=F[i-1]; ; ) {
				if(Y[j]==Y[i-1]) {
					F[i] = j + 1;
					break;
				}
				else if(j > 0) j = F[j];
				else break;
			}
		}
		memset(P,0,sizeof(P));
		for(i=0; i<ylen; i++) P[Y[i]] = true;
		for(i=0; i<MC; i++) if(P[i]) {
			for(j=0; j<ylen; j++) {
				k = j, tmp = 0;
				while(1) {
					if(Y[k]==(char)i) {
						tmp = k + 1;
						break;
					}
					else if(k>0) k = F[k];
					else break;
				}
				prec[j][i] = tmp;
			}
		}
		memset(dp,0,sizeof(dp));
		for(i=xlen-1; i>=0; i--) {
			for(j=0; j<=ylen; j++) {
				tmp = dp[j] + 1;
				if(prec[j][X[i]]!=ylen) tmp = min(tmp, dp[prec[j][X[i]]]);
				cp[j] = tmp;
			}
			for(j=0; j<=ylen; j++) dp[j] = cp[j];
		}
		cout<<dp[0]<<"\n";
	}
	return 0;
}
