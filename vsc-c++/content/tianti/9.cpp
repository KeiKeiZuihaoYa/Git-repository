#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 1e4 + 10;
bool mp[N][N];
int nowcnt;
bitset<1010> vis;

void dfs(int nowNode)
{
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> val(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        mp[u][v] = 1;
    }

    vector<vector<int>> v(n + 10);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (mp[i][j])
                v[i].push_back(j);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;

        nowcnt = 0;
        dfs(i);
        res = max(res, nowcnt);
    }
    cout << res;

    return 0;
}