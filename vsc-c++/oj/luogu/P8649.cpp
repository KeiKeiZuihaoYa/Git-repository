#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define ll long long
#define int long long
const int inf = 0x3f3f3f3f << 1;

int n, k;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    vector<int> a(n), sum(n);
    for (auto &i : a)
        cin >> i;

    sum[0] = a[0];
    for (int i = 1; i < n; i++)
        sum[i] = a[i] + sum[i - 1];

    unordered_map<int, int> mp;
    ++mp[0];
    for (auto &i : sum)
        i %= k, ++mp[i];

    // for (auto &i : sum)
    //     cout << i << ' ';

    int res = 0;
    for (auto &[_, i] : mp)
    {
        res += (i - 1) * i / 2;
    }
    cout << res;

    return 0;
}