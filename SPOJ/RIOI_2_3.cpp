#include <bits/stdc++.h>

using namespace std;

int n, sx, sy, ex, ey;
int a[51][51];
bool bio[51][51];
queue<pair<int, int> > red;
bool olk[11];

bool kr()
{
    queue<pair<int, int> > red;
    red.push(make_pair(sx, sy));
    memset(bio, 0, sizeof bio);
    while (!red.empty())
    {
        pair<int, int> ttk = red.front();
        red.pop();
        int x = ttk.first, y = ttk.second;
        if (x == ex && y == ey)
        {
            return true;
        }

        if (bio[x][y])
            continue;
        bio[x][y] = true;
        if (x - 1 >= 0 && !bio[x - 1][y])
        {
            if (olk[a[x - 1][y]])
            {
                red.push(make_pair(x - 1, y));
            }
        }
        if (y - 1 >= 0 && !bio[x][y - 1])
        {
            if (olk[a[x][y - 1]])
            {
                red.push(make_pair(x, y - 1));
            }
        }
        if (x + 1 < n && !bio[x + 1][y])
        {
            if (olk[a[x + 1][y]])
            {
                red.push(make_pair(x + 1, y));
            }
        }
        if (y + 1 < n && !bio[x][y + 1])
        {
            if (olk[a[x][y + 1]])
            {
                red.push(make_pair(x, y + 1));
            }
        }
    }

    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    int limit = 1 << 10;
    for (int tt = 0; tt < t; ++tt)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d",&a[i][j]);
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        int sol = 11;
        int bb = (1 << a[sx][sy]), kb = (1 << a[ex][ey]);
        for (int bitmk = 1; bitmk < limit; ++bitmk)
        {
            if (bitmk & bb
                && bitmk & kb)
            {
                memset(olk, 0, sizeof olk);
                int ll = 1;
                int i = 0;
                int size1 = 0;
                while (ll < limit)
                {
                    if (bitmk & ll)
                    {
                        ++size1;
                        olk[i] = true;
                    }
                    ll <<= 1;
                    ++i;
                }
                if (size1 < sol && kr())
                    sol = size1;
            }
        }
        printf("%d\n",sol);
    }
    return 0;
}
