#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    ll ans = 0;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    for (int i = 0; i < n - 1; i++)
    {
        int nowmin = inf, nowminindex;

        for (int j = i; j < n; j++)
            if (nowmin > v[j])
            {
                nowmin = v[j];
                nowminindex = j;
            }

        for (int j = nowminindex - 1; j >= i; j--)
            swap(v[j], v[j + 1]);

        ans += nowminindex - i;
    }

    cout << ans;

    return 0;
}