#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> vec(n + 10);
    vector<int> num(n + 10);

    auto add = [&](int x, int y) -> void
    {
        if (!y)
            return;
        vec[x].push_back(y);
        vec[y].push_back(x);
    };

    for (int i = 1; i <= n; i++)
    {
        int lc, rc;
        cin >> num[i] >> lc >> rc;
        add(i, lc);
        add(i, rc);
    }

    ll res = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        ll nowcnt = 0;
        bitset<200> vis;
        queue<P> q;
        q.push({i, 1});
        while (!q.empty())
        {
            P front = q.front();
            q.pop();
            int nowNode = front.first, nowDep = front.second;

            vis[nowNode] = 1;
            for (auto &i : vec[nowNode])
            {
                if (vis[i])
                    continue;
                q.push({i, nowDep + 1});
                nowcnt += num[i] * nowDep;
            }
        }
        res = min(res, nowcnt);
    }

    cout << res;

    return 0;
}