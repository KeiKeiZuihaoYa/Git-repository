#include <bits/stdc++.h>
using namespace std;

struct node
{
    int dep, size, top, fa, son;
    int sum;
};

int n;
vector<node> v;
vector<int> visa, ans;
vector<vector<int>> edge;

void dfs1(int cur, int fa)
{
    v[cur].dep = v[fa].dep + 1;
    v[cur].fa = fa;
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
    {
        if (i == v[cur].fa || i == v[cur].son)
            continue;
        dfs2(i, i);
    }
}

void lca(int a, int b)
{
    while (v[a].top != v[b].top)
    {
        if (v[v[a].top].dep < v[v[b].top].dep)
            swap(a, b);
        v[a].sum++;
        a = v[v[a].top].fa;
    }
    // return v[a].dep < v[b].dep ? a : b;
    if (v[a].dep < v[b].dep)
        swap(a, b);
    v[a].sum++;
    if (v[b].top != b)
        v[v[b].fa].sum--;
}

void dfs3(int cur)
{
    if (v[cur].son)
        dfs3(v[cur].son);
    v[cur].sum += v[v[cur].son].sum;
    for (auto &i : edge[cur])
    {
        if (i == v[cur].fa || i == v[cur].son)
            continue;
        dfs3(i);
    }
    ans[cur] += v[cur].sum;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    v.resize(n + 1);
    edge.resize(n + 1);
    ans.resize(n + 1);
    visa.resize(n);

    for (auto &i : visa)
        cin >> i;

    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs1(1, 0), dfs2(1, 1);

    for (int i = 1; i < n; i++)
    {
        int front = visa[i - 1], back = visa[i];
        lca(front, back);
    }

    for (int i = 1; i < n; i++)
        ans[visa[i]]--;

    dfs3(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}