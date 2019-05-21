#include <fstream>
#include <queue>

using namespace std;

ifstream fin("vila2.in");
ofstream fout("vila2.out");

const int oo = 0x3f3f3f3f;

int a[100005];

int main()
{
    int n,k;
    fin>>n>>k;
    ++k;
	deque <int> dqmin,dqmax;
	int ans = -oo;
	for(int i=1 ; i <= n ; ++i)
    {
        fin>>a[i];
        while(!dqmin.empty() && a[dqmin.back()]>=a[i])
            dqmin.pop_back();
        while(!dqmax.empty() && a[dqmax.back()]<=a[i])
            dqmax.pop_back();
        dqmin.push_back(i);
        dqmax.push_back(i);
        while(dqmin.front()<=i-k)
            dqmin.pop_front();
        while(dqmax.front()<=i-k)
            dqmax.pop_front();
        ans=max(ans,a[dqmax.front()]-a[dqmin.front()]);
    }
    fout<<ans;
    return 0;
}
