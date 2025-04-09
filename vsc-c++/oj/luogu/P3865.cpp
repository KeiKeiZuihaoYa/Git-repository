#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

inline int lc(const int &p) { return p << 1; }
inline int rc(const int &p) { return p << 1 | 1; }

vector<int> a, t;

inline void pushup(const int &p) { t[p] = max(t[lc(p)], t[rc(p)]); }

void build(int p, int l, int r)
{
    if (l == r)
    {
        t[p] = a[l];
        return;
    }

    int m = (l + r) >> 1;
    build(lc(p), l, m);
    build(rc(p), m + 1, r);
    pushup(p);
}

int query(int p, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return t[p];
    }

    int m = (l + r) >> 1, mx = INT_MIN;
    if (ql <= m)
        mx = max(mx, query(lc(p), l, m, ql, qr));
    if (m < qr)
        mx = max(mx, query(rc(p), m + 1, r, ql, qr));

    return mx;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    n = read(), m = read();

    a.resize(n + 1);
    t.resize((n + 1) << 2);

    for (int i = 1; i <= n; ++i)
        a[i] = read();
    build(1, 1, n);

    while (m--)
    {
        int a, b;
        a = read(), b = read();
        printf("%d\n", query(1, 1, n, a, b));
    }

    return 0;
}