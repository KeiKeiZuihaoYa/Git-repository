#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

int n, m;
vector<set<int>> v;
vector<int> ans, vis;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    v.resize(n);
    vis.resize(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].insert(b);
        v[b].insert(a);
    }

    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, -1});
    while (!q.empty() && ans.size() < n)
    {
        P front = q.top();
        q.pop();

        int now = front.first, f = front.second;
        if (!vis[front.first])
            vis[front.first] = 1, ans.push_back(front.first);
        else
            continue;

        for (auto &i : v[front.first])
        {
            if (i == f || vis[i])
                continue;
            q.push({i, now});
        }
    }

    for (auto &i : ans)
        cout << i + 1 << ' ';

    return 0;
}