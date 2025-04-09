#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node
{
    ll mx;
};

int n, m;
vector<ll> a;
vector<node> t;

inline int lc(const int &p) { return p << 1; }
inline int rc(const int &p) { return p << 1 | 1; }

inline void pushup(const int &p) { t[p].mx = max(t[lc(p)].mx, t[rc(p)].mx); }

void build(int p, int l, int r)
{
    if (l == r)
    {
        t[p].mx = a[l];
        return;
    }

    int m = (l + r) >> 1;
    build(lc(p), l, m);
    build(rc(p), m + 1, r);
    pushup(p);
}

void update(int p, int l, int r, int uindex, ll val)
{
    if (l == r && l == uindex)
    {
        t[p].mx = val;
        return;
    }

    int m = (l + r) >> 1;
    if (uindex <= m)
        update(lc(p), l, m, uindex, val);
    else
        update(rc(p), m + 1, r, uindex, val);
    pushup(p);
}

ll query(int p, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return t[p].mx;
    }

    int m = (l + r) >> 1;
    ll mx = LLONG_MIN;
    if (ql <= m)
        mx = max(mx, query(lc(p), l, m, ql, qr));
    if (m < qr)
        mx = max(mx, query(rc(p), m + 1, r, ql, qr));
    return mx;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    while (cin >> n >> m)
    {
        a.resize(n + 1);
        t.resize((n + 1) << 2);

        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        build(1, 1, n);

        char op;
        int a, b;
        while (m--)
        {
            cin >> op >> a >> b;
            if (op == 'Q')
            {
                cout << query(1, 1, n, a, b) << '\n';
            }
            else
            {
                update(1, 1, n, a, b);
            }
        }
    }

    return 0;
}