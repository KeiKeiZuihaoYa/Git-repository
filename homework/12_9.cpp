#include <bits/stdc++.h>
using namespace std;
#define ll long long

void zuidatuan()
{
    int n, m; // n - 点数 m - 边数
    cin >> n >> m;
    vector<vector<bool>> edge(n, vector<bool>(n));
    vector<bool> vis(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a][b] = edge[b][a] = true;
    }

    int ans = 0;
    vector<int> used, maxx;
    function<void(int)> dfs = [&](int x)
    {
        // exit
        if (x >= n)
        {
            maxx.clear();
            for (auto i : used)
                maxx.push_back(i + 1);
            return;
        }

        // check whether legal
        bool flag = true;
        for (auto i : used)
            if (edge[i][x])
            {
                flag = false;
                break;
            }

        // choose current node
        if (flag)
        {
            used.push_back(x);
            ans++;
            dfs(x + 1);
            used.pop_back();
            ans--;
        }
        // do not choose current node and check whether it is better than previous
        if (used.size() + n - x - 1 > ans)
            dfs(x + 1);
    };

    // run code
    dfs(0);
    // print maxx
    for (auto i : maxx)
        cout << i << ' ';
    cout << '\n';
}

void travel()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n, vector<int>(n, INT_MAX));
    vector<vector<ll>> dp(1 << n, vector<ll>(n, INT_MAX)); // 开 long long 防溢出
    for (int i = 0; i < n; i++)
        edge[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge[a][b] = edge[b][a] = min(edge[a][b], c);
    }

    // dp -> 二进制状压
    dp[1][0] = 0;
    for (int i = 0; i < 1 << n; i++) // i 城市集合
        for (int j = 0; j < n; j++)  //
            if (i >> j & 1)          // 含 j 城市
                for (int k = 0; k < n; k++)
                    if (i >> k & 1)                                                 // 含 k 城市
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + edge[k][j]); // 去 i 的城市集合 减去 j，再加上 k 到 j 的距离

    ll res = INT_MAX;
    for (int i = 0; i < n; i++)
        res = min(res, dp[(1 << n) - 1][i] + edge[i][0]);
    cout << res << '\n';
}

void mColor()
{
    int n, m, res = INT_MAX;
    cin >> n >> m;
    vector<int> color(n), edge[n];

    // input graph
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    function<void(int, int)> dfs = [&](int now, int tot)
    {
        // all nodes' colour filled
        if (now >= n)
        {
            res = min(res, tot);
            return;
        }

        bool flag = false; // among current colors that whether can be used
        for (int i = 1; i <= tot; i++)
        {
            bool canused = true;
            for (auto j : edge[now])
                if (color[j] == i)
                {
                    canused = false;
                    break;
                }

            // legal
            if (canused)
            {
                flag = true;
                color[now] = i;
                dfs(now + 1, tot);
                color[now] = 0;
            }
        }

        if (!flag)
        {
            color[now] = tot + 1;
            dfs(now + 1, tot + 1);
            color[now] = 0;
        }
    };

    dfs(0, 1);
    cout << res << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    zuidatuan();
    travel();
    mColor();

    return 0;
}