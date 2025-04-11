#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

struct nodeL
{
    int top, size, fa, son, dep, dfn;
} vl[N];
struct nodeS
{
    int sum = 0, lz = -1;
} vs[N << 2];

int n, m, tim;
vector<int> e[N];

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
        vl[cur].son = vl[vl[cur].son].size < vl[i].size ? i : vl[cur].son;
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
inline void lazy(int p, int l, int r, int lz) { vs[p].lz = lz, vs[p].sum = lz * (r - l + 1); }

void pushdown(const int &p, const int &l, const int &r)
{
    int m = (l + r) >> 1;
    lazy(lc(p), l, m, vs[p].lz);
    lazy(rc(p), m + 1, r, vs[p].lz);
    vs[p].lz = -1;
}

void update(int id, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr)
    {
        vs[id].sum = val * (r - l + 1);
        vs[id].lz = val;
        return;
    }
    if (vs[id].lz != -1)
        pushdown(id, l, r);
    int m = (l + r) >> 1;
    if (ql <= m)
        update(lc(id), l, m, ql, qr, val);
    if (m < qr)
        update(rc(id), m + 1, r, ql, qr, val);
    pushup(id);
}

int query(int p, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return vs[p].sum;

    if (vs[p].lz != -1)
        pushdown(p, l, r);
    int m = (l + r) >> 1, res = 0;
    if (ql <= m)
        res += query(lc(p), l, m, ql, qr);
    if (m < qr)
        res += query(rc(p), m + 1, r, ql, qr);
    return res;
}

int install(int cur)
{
    int t = vs[1].sum;
    while (vl[cur].top != 1)
    {
        int nowtop = vl[cur].top;
        update(1, 1, n, vl[nowtop].dfn, vl[cur].dfn, 1);
        cur = vl[nowtop].fa;
    }
    update(1, 1, n, 1, vl[cur].dfn, 1);
    return abs(t - vs[1].sum);
}

int uninstall(int cur)
{
    int ans = vs[1].sum;
    update(1, 1, n, vl[cur].dfn, vl[cur].dfn + vl[cur].size - 1, 0);
    return abs(ans - vs[1].sum);
}

int read()
{
    char ch = getchar();
    int res = 0, w = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return res * w;
}

signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    n = read();
    for (int i = 2, tmp; i <= n; i++)
    {
        tmp = read() + 1;
        e[tmp].push_back(i);
    }

    dfs1(1, 1), dfs2(1, 1);
    m = read();
    string op;
    int x;
    while (m--)
    {
        cin >> op;
        x = read() + 1;
        if (op[0] == 'i')
            printf("%d\n", install(x));
        else
            printf("%d\n", uninstall(x));
    }

    return 0;
}