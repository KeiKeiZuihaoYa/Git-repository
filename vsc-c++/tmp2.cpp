#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    ll t;
    cin >> t;
    queue<ll> q;
    ll a, b;
    ll dis[10000];
    ll vis[10000];
    while (t--)
    {

        ll n, d;
        cin >> n >> d;
        ll cnt = 0;
        vector<vector<ll>> edge(n + 10);
        vector<ll> dian(n + 10);
        for (ll i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        q.push(0);
        ll f = q.front();
        while (!q.empty())
        {
            for (auto i : edge[f])
            {
                if (vis[i] == 1)
                {
                    continue;
                }
                q.push(i);
                dis[i] = dis[f] + 1;
            }
            vis[f] = 1;
            q.pop();
        }
        for (ll j = 0; j < n; j++)
        {
            if (dis[j] > 2)
                cnt++;
        }
        cout << cnt;
    }

    return 0;
}