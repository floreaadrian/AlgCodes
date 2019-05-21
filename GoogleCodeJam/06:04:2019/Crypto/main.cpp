#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

ifstream fin("data.in");
ofstream fout("data.out");

unsigned int gcd(unsigned int u, unsigned int v)
{
    int shift;
    if (u == 0)
        return v;
    if (v == 0)
        return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do
    {
        v >>= __builtin_ctz(v);
        if (u > v)
        {
            unsigned int t = v;
            v = u;
            u = t;
        }
        v = v - u;
    } while (v != 0);
    return u << shift;
}

int main()
{
    long t;
    fin >> t;
    for (long tt = 1; tt <= t; ++tt)
    {
        fout << "Case #" << tt << ": ";
        int n, l;
        set<int> cnt;
        fin >> n >> l;
        vector<int> code(l), p(l + 1);
        vector<char> ret(l + 1);
        for (int i = 0; i < l; i++)
            fin >> code[i];
        p[1] = gcd(code[0], code[1]);
        p[0] = code[0] / p[1];
        for (int i = 1; i < l; i++)
            p[i + 1] = code[i] / p[i];
        for (int e : p)
            cnt.insert(e);
        int x = 0;
        for (int e : cnt)
        {
            for (int i = 0; i <= l; i++)
                if (p[i] == e)
                    ret[i] = x + 'A';
            x++;
        }
        for (char c : ret)
            fout << c;
        fout << '\n';
    }
}