#include <bits/stdc++.h>
using namespace std;

struct node
{
    int dep, top, size, fa, son;
};

int n;
vector<node> v;
vector<vector<int>> edge;

// process dep son fa
void dfs1(int cur, int f)
{
    v[cur].fa = f;
    v[cur].size = 1;
    v[cur].dep = v[f].dep + 1;
    for (auto &i : edge[cur])
    {
        if (i == f)
            continue;
        dfs1(i, cur);
        v[cur].size += v[i].size;
        v[cur].son = (v[v[cur].son].size < v[i].size ? i : v[cur].son);
    }
}

// process top
void dfs2(int cur, int t)
{
    v[cur].top = t;
    if (!v[cur].son)
        return;
    dfs2(v[cur].son, t);
    for (auto &i : edge[cur])
    {
        if (i == v[cur].fa || i == v[cur].son)
            continue;
        dfs2(i, i);
    }
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

    cin >> n;
    v.resize(n + 1);

    return 0;
}