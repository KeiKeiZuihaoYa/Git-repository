#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;

int n, m, s;
struct E
{
    int u, v, w;
};
struct node
{
    int dis, v;
    bool operator<(const node &a) const
    {
        return dis > a.dis;
    }
};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> s;
    s--;

    vector<vector<E>> edge(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[u].push_back({u, v, w});
    }

    vector<ll> dis(n, 1e18);
    vector<int> vis(n);
    priority_queue<node> q;
    dis[s] = 0;
    vis[s] = 1;
    for (auto i : edge[s])
        q.push({i.w, i.v});

    while (!q.empty())
    {
        auto f = q.top();
        q.pop();
        if (vis[f.v])
            continue;

        vis[f.v] = 1;
        dis[f.v] = f.dis;

        for (auto i : edge[f.v])
            if (!vis[i.v])
                q.push({f.dis + i.w, i.v});
    }

    for (auto i : dis)
        cout << i << " ";

    return 0;
}