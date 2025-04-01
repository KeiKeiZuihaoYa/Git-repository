#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> sum(n), a(n);
    for (auto &i : a)
        cin >> i;
    sum[0] = a[0];
    for (int i = 1; i < n; i++)
        sum[i] = a[i] + sum[i - 1];

    multiset<int> nowRightTotal;
    unordered_map<int, multiset<int>> mps;

    for (int i = 1; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
            mps[i].insert(sum[j] - sum[i - 1]);
        nowRightTotal.insert(mps[i].begin(), mps[i].end());
    }

    int ans = LONG_LONG_MAX;
    for (int t = 0; t < n - 1; t++) // r0
    {
        for (auto &i : mps[t])
            nowRightTotal.erase(nowRightTotal.find(i));
        mps.erase(t);

        for (int l = 0; l <= t; ++l)
        {
            int nowsum = sum[t] - (l ? sum[l - 1] : 0);
            auto it = nowRightTotal.lower_bound(nowsum);
            if (nowsum == *it)
            {
                ans = 0;
                goto br;
            }
            ans = min(ans, abs(nowsum - *(it)));
            if (it != nowRightTotal.begin())
            {
                --it;
                ans = min(ans, abs(nowsum - *(it)));
            }
        }
    }
br:
    cout << ans;

    return 0;
}