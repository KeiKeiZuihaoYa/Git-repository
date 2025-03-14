#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
bool work()
{
    int n, m;
    cin >> n >> m;
    map<P, int> mp;
    vector<vector<P>> edge(n);
    vector<int> dis(n, 1e9), cnt(n);

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        auto tmp = mp.find({a, b});
        if (tmp == mp.end())
        {
            mp[{a, b}] = c;
            if (c >= 0)
                mp[{b, a}] = c;
        }
        else if (c < tmp->second)
        {
            tmp->second = c;
            if (c >= 0)
                mp[{b, a}] = c;
        }
    }
    for (auto i : mp)
        edge[i.first.first].push_back({i.first.second, i.second});

    queue<int> q;
    dis[0] = 0;
    cnt[0] = 1;
    q.push(0);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        if (++cnt[f] >= n)
            return 1;

        for (auto &[v, w] : edge[f])
        {
            if (dis[v] > dis[f] + w)
            {
                dis[v] = dis[f] + w;
                q.push(v);
            }
        }
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        if (work())
            cout << "YES\n";
        else
            cout << "NO\n";

    return 0;
}