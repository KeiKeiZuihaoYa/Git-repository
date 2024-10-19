#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, ll> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 1010;

int n, m;
vector<int> edge[N];
int vis[N], f[N][N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m && n && m)
    {
        for (int i = 0; i <= n; i++)
            edge[i].clear();

        memset(f, 0, sizeof f);
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (f[a][b])
                continue;
            edge[a].push_back(b);
            edge[b].push_back(a);
            f[a][b] = 1;
            f[b][a] = 1;
        }

        ll res = -inf;
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof vis);
            queue<P> q;
            q.push({i, 0});
            while (!q.empty())
            {
                P f = q.front();
                q.pop();
                vis[f.first] = 1;
                res = max(res, f.second);
                for (auto i : edge[f.first])
                {
                    if (vis[i])
                        continue;
                    vis[i] = 1;
                    q.push({i, f.second + 1});
                }
            }
        }
        cout << res * 100 << "\n";
    }
    return 0;
}