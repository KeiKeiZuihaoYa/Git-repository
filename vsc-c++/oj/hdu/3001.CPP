#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

vector<int> add(10);
void init()
{
    for (int i = 0, tmp = 1; i < 10; i++, tmp *= 3)
        add[i] = tmp;
}

int get_index(int x, int pos)
{
    while (pos--)
        x /= 3;
    return x % 3;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    init();

    int n, m;
    while (cin >> n >> m)
    {
        int limit = pow(3, n), res = INT_MAX;
        vector<vector<int>> edge(n, vector<int>(n, INT_MAX));
        vector<vector<ll>> dp(limit, vector<ll>(n, INT_MAX));
        for (int i = 0; i < n; i++)
            edge[i][i] = 0;
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            edge[a][b] = edge[b][a] = min(edge[a][b], c);
        }

        for (int i = 0; i < n; i++)
            dp[pow(3, i)][i] = 0;

        for (int i = 0; i < limit; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (get_index(i, j)) // 存在
                {
                    cnt++;
                    for (int k = 0; k < n; k++)
                        if (get_index(i, k) < 2) // 没超出上限
                            dp[i + add[k]][k] = min(dp[i + add[k]][k], dp[i][j] + edge[j][k]);
                }

            if (cnt == n)
                for (int j = 0; j < n; j++)
                    res = min(res, dp[i][j]);
        }

        if (res == INT_MAX)
            res = -1;
        cout << res << '\n';
    }

    return 0;
}