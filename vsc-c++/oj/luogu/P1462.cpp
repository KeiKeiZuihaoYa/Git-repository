#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
struct node
{
    ll blood, now, money;
    bool operator<(const node &a) const
    {
        return money != a.money ? money > a.money : blood < a.blood;
    }
};
int n, m, b;
vector<int> fcity;
vector<vector<pair<int, ll>>> edge; // {v, w}

bool dijkstra()
{
    vector<ll> dis(n, INT_MAX);
    vector<bool> vis(n, false);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, 0});
    dis[0] = 0;
    while (!q.empty())
    {
        auto [d, u] = q.top();
        q.pop();

        if (vis[u])
            continue;
        vis[u] = true;
        dis[u] = d;
        if (u == n - 1)
            return true;

        for (auto [v, w] : edge[u])
        {
            if (vis[v])
                continue;
            q.push({d + w, v});
        }
    }
    return false;
}

bool check(ll mid)
{
    vector<bool> vis(n, false);
    priority_queue<node> q; // {blood cost, nownode, money}
    q.push({b, 0, 0});

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();

        if (vis[f.now])
            continue;
        vis[f.now] = 1;

        if (f.now == n - 1)
            return true;

        for (auto [v, w] : edge[f.now])
        {
            if (vis[v] || f.blood < w)
                continue;

            
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> b;
    fcity.resize(n), edge.resize(n);
    for (auto &i : fcity)
        cin >> i;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == b)
            continue;
        a--, b--;

        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    if (!dijkstra()) // 不可达
        cout << "AFK";

    ll l = 0, r = 1e18, mid, res;
    while (l <= r)
    {
        mid = (l + r) >> 1;

        if (check(mid))
            res = mid, r = mid - 1;
        else
            l = mid + 1;
    }

    return 0;
}