#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> fama(n);

    for (auto &i : fama)
        cin >> i;

    vector<vector<bool>> dp(n, vector<bool>(N, false));
    dp[0][fama[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < N; j++)
        {
            dp[i][j] = dp[i][j] || dp[i - 1][j] || (j == fama[i]) || dp[i - 1][abs(j - fama[i])];
            if (j + fama[i] < N)
                dp[i][j] = dp[i][j] || dp[i - 1][j + fama[i]];
        }
    }
    int cnt = 0;
    for (int i = 1; i < N; i++)
        cnt += dp[n - 1][i];
    cout << cnt;
    return 0;
}

/*

4
1 6 8 17

*/