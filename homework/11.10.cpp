#include <bits/stdc++.h>
using namespace std;

int problem_01bag()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = j >= v[i] ? max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]) : dp[i - 1][j];

    return dp[n][m];
}

int problemLineScheduling()
{
    int n;
    cin >> n;
    vector<int> a1(n), a2(n), t1(n), t2(n);
    for (auto &i : a1)
        cin >> i;
    for (auto &i : a2)
        cin >> i;
    for (auto &i : t1)
        cin >> i;
    for (auto &i : t2)
        cin >> i;

    vector<vector<int>> dp(2, vector<int>(n));
    dp[0] = vector<int>({a1.front(), a2.front()});
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = min(dp[0][i - 1], dp[1][i - 1] + t2[i]) + t1[i];
        dp[1][i] = min(dp[1][i - 1], dp[0][i - 1] + t1[i]) + t2[i];
    }
    return min(dp[0].back(), dp[1].back();
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cout << problem_01bag() << '\n';         // 0-1背包问题
    cout << problemLineScheduling() << '\n'; // 装配线调度问题

    return 0;
}