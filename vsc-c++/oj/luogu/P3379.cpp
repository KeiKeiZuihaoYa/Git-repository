#include <bits/stdc++.h>
using namespace std;

struct node
{
    int top, size, dep, fa, son;
};

int n, m, s;
vector<node> v;
vector<vector<int>> edge;

void dfs1(int cur, int fa)
{
    v[cur].fa = fa;
    v[cur].dep = v[fa].dep + 1;
    v[cur].size = 1;
    for (auto &i : edge[cur])
    {
        if (i == fa)
            continue;
        dfs1(i, cur);
        v[cur].size += v[i].size;
        v[cur].son = v[i].size > v[v[cur].son].size ? i : v[cur].son;
    }
}

void dfs2(int cur, int top)
{
    v[cur].top = top;
    if (!v[cur].son)
        return;
    dfs2(v[cur].son, top);
    for (auto &i : edge[cur])
        if (i == v[cur].fa || i == v[cur].son)
            continue;
        else
            dfs2(i, i);
}

int lca(int n1, int n2)
{
    while (v[n1].top != v[n2].top)
    {
        if (v[v[n1].top].dep < v[v[n2].top].dep)
            swap(n1, n2);
        n1 = v[v[n1].top].fa;
    }
    return v[n1].dep < v[n2].dep ? n1 : n2;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> s;
    v.resize(n + 1);
    edge.resize(n + 1);

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    dfs1(s, 0), dfs2(s, s);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}