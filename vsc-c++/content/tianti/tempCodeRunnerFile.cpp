#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 1e5 + 10;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    set<int> s;
    unordered_map<int, int> mp;
    int n, now;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> now;
        s.insert(now);
        mp[now]++;
    }
    vector<int> v;
    for (auto &i : s)
        v.push_back(i);

    vector<vector<int>> dp(v.size(), vector<int>(2));
    dp[0][0] = 0, dp[0][1] = mp[v[0]] * v[0];
    for (int i = 1; i < v.size(); i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = mp[v[i]] * v[i] + dp[i - 1][0];
    }

    cout << max(dp[v.size() - 1][0], dp[v.size() - 1][1]);

    // for(auto &vec : dp)
    // {
    //     for(auto &i : vec)
    //         cout << i << ' ';
    //     cout << '\n';
    // }

    return 0;
}