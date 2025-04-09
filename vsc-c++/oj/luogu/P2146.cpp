#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;

struct nodeL
{
    int top, size, fa, son, dep, dfn;
};
struct nodeS
{
    int sum, lz;
};

int n, m, tim;
vector<nodeL> vl;
vector<nodeS> vs;
vector<vector<int>> e;

void dfs1(int cur, int fa)
{
    vl[cur].fa = fa;
    vl[cur].dep = vl[fa].dep + 1;
    vl[cur].size = 1;

    for (auto &i : e[cur])
    {
        if (i == fa)
            continue;
        dfs1(i, cur);
        vl[cur].size += vl[i].size;
        vl[cur].son = vl[cur].son < vl[i].size ? i : vl[cur].son;
    }
}

void dfs2(int cur, int top)
{
    vl[cur].top = top;
    vl[cur].dfn = ++tim;
    if (!vl[cur].son)
        return;
    dfs2(vl[cur].son, top);
    for (auto &i : e[cur])
    {
        if (i == vl[cur].fa || i == vl[cur].son)
            continue;
        dfs2(i, i);
    }
}

inline int lc(const int &p) { return p << 1; }
inline int rc(const int &p) { return p << 1 | 1; }

inline void pushup(const int &p) { vs[p].sum = vs[lc(p)].sum + vs[rc(p)].sum; }
inline void lazy(int p, int l, int r, int lz)
{
    vs[p].lz = lz;
    if (lz == 1)
        vs[p].sum = r - l + 1;
    else
        vs[p].sum = 0;
}

void pushdown(const int &p, const int &l, const int &r)
{
    if (vs[p].lz == 0)
        return;

    int m = (l + r) >> 1;
    lazy(lc(p), l, m, vs[p].lz);
    lazy(rc(p), m + 1, r, vs[p].lz);
    vs[p].lz = 0;
}

void update(int id, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr)
    {
        if (val == 1)
            vs[id].sum = (r - l + 1);
        else
            vs[id].sum = 0;
        vs[id].lz = val;
        return;
    }

    if (vs[id].lz == val)
        return;

    pushdown(id, l, r);
    int m = (l + r) >> 1;
    if (ql <= m)
        update(lc(id), l, m, ql, qr, val);
    if (m < qr)
        update(rc(id), m + 1, r, ql, qr, val);
    pushup(id);
}

int install(int cur)
{
    int before = vs[1].sum, after = 0;
    while (cur)
    {
        update(1, 1, n, vl[vl[cur].top].dfn, vl[vl[cur].top].dfn + vl[cur].dep - vl[vl[cur].top].dep, 1);
        cur = vl[vl[cur].top].fa;
    }
    after = vs[1].sum;
    return after - before;
}

int uninstall(int cur)
{
    int before = vs[1].sum, after;
    update(1, 1, n, vl[cur].dfn, vl[cur].dfn + vl[cur].size - 1, -1);
    after = vs[1].sum;
    return before - after;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    vl.resize(n + 1);
    e.resize(n + 1);
    vs.resize((n + 1) << 2, {0, 0});
    for (int i = 1, tmp; i < n; i++)
    {
        cin >> tmp;
        if (tmp == 0)
            tmp = n;
        e[tmp].push_back(i);
        e[i].push_back(tmp);
    }

    dfs1(n, 0), dfs2(n, n);
    cin >> m;
    string op;
    int x;
    while (m--)
    {
        cin >> op >> x;
        if (!x)
            x = n;
        if (op[0] == 'i')
            cout << install(x);
        else
            cout << uninstall(x);
        cout << '\n';
    }

    return 0;
}