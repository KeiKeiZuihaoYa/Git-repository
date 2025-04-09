#include <bits/stdc++.h>
using namespace std;

struct node
{
    int lz = 0;
    int sum = 0;
};

inline int lc(const int &p) { return p << 1; }
inline int rc(const int &p) { return p << 1 | 1; }

int n, m;
vector<int> a;
vector<node> t;

inline void pushup(const int &p)
{
    t[p].sum = t[lc(p)].sum + t[rc(p)].sum;
}

inline void lazy(const int &p, int l, int r, int lz)
{
    t[p].lz += lz;
    t[p].sum += (r - l + 1) * lz;
}

void pushdown(const int &p, int l, int r)
{
    int mid = (l + r) >> 1;
    lazy(lc(p), l, mid, t[p].lz);
    lazy(rc(p), mid + 1, r, t[p].lz);
    t[p].lz = 0;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        t[id].sum = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(lc(id), l, mid);
    build(rc(id), mid + 1, r);
    pushup(id);
}

void update(int id, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr)
    {
        t[id].lz += val;
        t[id].sum += (r - l + 1) * val;
        return;
    }

    pushdown(id, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        update(lc(id), l, mid, ql, qr, val);
    if (mid < qr)
        update(rc(id), mid + 1, r, ql, qr, val);
    pushup(id);
}

int query(int id, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return t[id].sum;
    }

    pushdown(id, l, r);
    int mid = (l + r) >> 1, res = 0;
    if (ql <= mid)
        res += query(lc(id), l, mid, ql, qr);
    if (mid < qr)
        res += query(rc(id), mid + 1, r, ql, qr);
    return res;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    a.resize(n + 1);
    t.resize((n + 1) << 2);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    int op, x, y, k;
    while (m--)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            cin >> k;
            update(1, 1, n, x, y, k);
        }
        else
        {
            cout << query(1, 1, n, x, y) << '\n';
        }
    }

    return 0;
}

/*

第一行包含两个整数 n,m，分别表示该数列数字的个数和操作的总个数。

第二行包含 n 个用空格分隔的整数 ai ，其中第 i 个数字表示数列第 i 项的初始值。

接下来 m 行每行包含 3 或 4 个整数，表示一个操作，具体如下：

1 x y k：将区间 [x,y] 内每个数加上 k。
2 x y：输出区间 [x,y] 内每个数的和。

*/