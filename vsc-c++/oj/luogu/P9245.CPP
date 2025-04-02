#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> P;

struct node
{
    int size, top, dep, height, fa, son;
};

int n, k;
vector<int> visa;
vector<node> v;
vector<vector<P>> edge; // node, length

void dfs1(int cur, int fa)
{
    v[cur].fa = fa;
    v[cur].dep = v[fa].dep + 1;
    v[cur].size = 1;
    for (auto &[i, j] : edge[cur])
    {
        if (i == fa)
            continue;
        v[i].height = v[cur].height + j;
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
    for (auto &[i, j] : edge[cur])
    {
        if (i == v[cur].fa || i == v[cur].son)
            continue;
        dfs2(i, i);
    }
}

int lca(int a, int b)
{
    while (v[a].top != v[b].top)
    {
        if (v[v[a].top].dep < v[v[b].top].dep)
            swap(a, b);
        a = v[v[a].top].fa;
    }
    return v[a].dep < v[b].dep ? a : b;
}

int work(int a1, int a2)
{
    return v[a1].height + v[a2].height - (v[lca(a1, a2)].height << 1);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    v.resize(n + 1);
    edge.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    dfs1(1, 0), dfs2(1, 1);

    visa.resize(k);
    for (auto &i : visa)
        cin >> i;

    int sum = 0;
    for (int i = 1; i < k; i++)
    {
        sum += work(visa[i], visa[i - 1]);
    }

    for (int i = 1; i <= k; i++)
    {
        int skippedpoint = visa[i - 1], nowpoint = 0, skiplastpoint = 0;
        int yuan = 0, xin = 0;
        if (i != 1)
            skiplastpoint = visa[i - 2];
        if (i != k)
            nowpoint = visa[i];
        if (i == 1)
        {
            yuan = work(skippedpoint, nowpoint);
        }
        else if (i == k)
        {
            yuan = work(skippedpoint, skiplastpoint);
        }
        else
        {
            yuan = work(skiplastpoint, skippedpoint) + work(skippedpoint, nowpoint);
            xin = work(skiplastpoint, nowpoint);
        }
        cout << sum - (yuan - xin) << ' ';
    }

    return 0;
}