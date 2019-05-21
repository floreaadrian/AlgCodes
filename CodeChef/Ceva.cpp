#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

struct P {
    int x, y;
    P operator - (const P & b) const {
        return P{x - b.x, y - b.y};
    }
    int operator * (const P & b) const {
        return x * b.y - y * b.x;
    }
};

#define left left_compile
#define right right_compile
int left[nax], right[nax], h[nax];
bool left_vis[nax], right_vis[nax];

bool see(int i, int j) { // does i see j?
    assert(i != j);
    P a, c;
    if(i < j) {
        a = P{right[i], h[i]};
        c = P{left[j], 0};
    }
    else {
        a = P{right[j], 0};
        c = P{left[i], h[i]};
    }
    FOR(k, min(i,j)+1, max(i,j)-1) REP(rep, 2) {
        P b = P{rep ? right[k] : left[k], h[k]};
        if((b - a) * (c - a) < 0)
            return false;
    }
    return true;
}

int solve(int from, int to, int nnn) { // be careful with nnn
    if(from > to) return 0;
    pii max_h = mp(-1, -1);
    FOR(i, from, to) maxi(max_h, mp(h[i], i));
    int mid = max_h.nd;
    int ans = 0;
    if(mid - 1 >= 0 && !right_vis[mid-1]) {
        ++ans;
        left_vis[mid] = true;
        FOR(i, 0, mid - 1)
            if(see(mid, i))
    				right_vis[i] = true;
    	}
    	if(mid + 1 <= nnn-1 && !left_vis[mid+1]) {
    		++ans;
    		right_vis[mid] = true;
    		FOR(i, mid + 1, nnn - 1)
    			if(see(mid, i))
    				left_vis[i] = true;
    	}
    return ans + solve(from, mid - 1, nnn) + solve(mid + 1, to, nnn);
}

void te() {
    int n;
    scanf("%d", &n);
    vector<vi> in;
    REP(_, n) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        in.pb(vi{a,b,c});
    }
    sort(in.begin(), in.end());
    	REP(i, n) {
        vi & x = in[i];
    		left[i] = x[0];
    		right[i] = x[1];
    		h[i] = x[2];
    	}
    	// REP(i, n) printf("%d %d %d\n", left[i], right[i], h[i]);
    	int ans = solve(0, n - 1, n);
    	REP(i, n) {
    		ans += !left_vis[i];
    		ans += !right_vis[i];
    		left_vis[i] = right_vis[i] = false;
    	}
    printf("%d\n", ans);
}

int main() {
    	int z;
    	scanf("%d", &z);
    	while(z--) te();
    	return 0;
}
