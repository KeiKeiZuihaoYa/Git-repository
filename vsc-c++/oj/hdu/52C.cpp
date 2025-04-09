#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

struct node
{
    ll mn;
    ll lz;
};

int n, m, tmp, lg, rg;
ll k;
vector<ll> a;
vector<node> t;

inline int lc(const int &p) { return p << 1; }
inline int rc(const int &p) { return p << 1 | 1; }

inline void pushup(const int &p) { t[p].mn = min(t[lc(p)].mn, t[rc(p)].mn); }

inline void lazy(const int &p, ll lz)
{
    t[p].mn += lz;
    t[p].lz += lz;
}

void pushdown(const int &p)
{
    if (t[p].lz == 0)
        return;

    lazy(lc(p), t[p].lz);
    lazy(rc(p), t[p].lz);
    t[p].lz = 0;
}

void build(int p, int l, int r)
{
    t[p].mn = LLONG_MAX;
    t[p].lz = 0;
    if (l == r)
    {
        t[p].mn = a[l];
        return;
    }

    int m = (l + r) >> 1;
    build(lc(p), l, m);
    build(rc(p), m + 1, r);
    pushup(p);
}

void update(int p, int l, int r, int ql, int qr, ll val)
{
    if (ql <= l && r <= qr)
    {
        t[p].mn += val;
        t[p].lz += val;
        return;
    }

    pushdown(p);
    int m = (l + r) >> 1;
    if (ql <= m)
        update(lc(p), l, m, ql, qr, val);
    if (m < qr)
        update(rc(p), m + 1, r, ql, qr, val);
    pushup(p);
}

ll query(int p, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return t[p].mn;
    }

    pushdown(p);
    ll res = LLONG_MAX;
    int m = (l + r) >> 1;
    if (ql <= m)
        res = min(res, query(lc(p), l, m, ql, qr));
    if (m < qr)
        res = min(res, query(rc(p), m + 1, r, ql, qr));
    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    a.resize(n + 1);
    t.resize((n + 1) << 2);

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, 1, n);

    cin >> m;
    cin.ignore();
    string line;
    while (m--)
    {
        getline(cin, line);
        istringstream is(line);
        vector<int> v;
        while (is >> tmp)
            v.push_back(tmp);
        ++v[0], ++v[1];

        if (v.size() == 3)
        {
            lg = v[0], rg = v[1], k = v[2];
            if (lg > rg)
            {
                update(1, 1, n, lg, n, k);
                update(1, 1, n, 1, rg, k);
            }
            else
                update(1, 1, n, lg, rg, k);
        }
        else
        {
            lg = v[0], rg = v[1];
            if (lg > rg)
            {
                cout << min(query(1, 1, n, lg, n), query(1, 1, n, 1, rg)) << '\n';
            }
            else
            {
                cout << query(1, 1, n, lg, rg) << '\n';
            }
        }
    }

    return 0;
}