#include<fstream>  
#define lg 100003  
using namespace std;
long n, m, i, x, init[lg], poz, p1, p2, l2, rsp;  
   
struct arbore_int{  
    int x, y, sm, rp;  
};  
arbore_int q[4*lg];  
   
inline long max(long a, long b){  
    return a > b ? a : b;  
}  
   
void construiesc(int st, int dr, int poz){  
    if (st == dr){  
        init[st] = poz;  
        return ;  
    }  
   
    int x = (st+dr) / 2;  
   
    construiesc(st, x, 2*poz);  
    construiesc(x+1, dr, 2*poz+1);  
}  
void actualizez(long poz){  
    for (; poz; poz /= 2){  
        q[poz].sm = q[2*poz].sm + q[2*poz+1].sm;  
        q[poz].x = max(q[2*poz].x, q[2*poz].sm + q[2*poz+1].x);  
        q[poz].y = max(q[2*poz+1].y, q[2*poz+1].sm + q[2*poz].y);  
        q[poz].rp = max(q[2*poz].rp, q[2*poz+1].rp);
        q[poz].rp = max(q[poz].rp, q[2*poz].y + q[2*poz+1].x);  
    }  
}  
void interogare(long st, long dr, long poz){  
    if (st >= p1 && dr <= p2){  
   
        rsp = max(rsp, q[poz].rp); rsp = max(rsp, l2 + q[poz].x);  
        l2 = max(q[poz].y, l2 + q[poz].sm);  
   
        return ;  
    }  
    if (st > p2 || dr < p1 || st == dr)  
        return ;  
   
    int x = (st+dr) / 2;  
    interogare(st, x, 2*poz);  
    interogare(x+1, dr, 2*poz+1);  
}  
   
int main()  
{  
   ifstream f("sequencequery.in");  
    ofstream g("sequencequery.out");  
   
    f>>n>>m;  
    construiesc(1, n, 1);  
   
    for (i = 1; i <= n; i ++){  
        f>>x; 
   
        poz = init[i];  
        q[poz].x = q[poz].y = q[poz].rp = q[poz].sm = x;  
   
        actualizez(poz / 2);  
    }  
   
    for (i = 1; i <= m; i ++){  
       f>>p1>>p2;
   
        rsp = -0x3f3f3f3f, l2 = -0x3f3f3f3f;  
        interogare(1, n, 1);  
   
        g<<rsp<<"\n";  
    }  
      f.close();
      g.close();
       
    return 0;  
}
