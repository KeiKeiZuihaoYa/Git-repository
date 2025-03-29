#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll _, a, b;
    cin >> _;
    while (_--)
    {
        cin >> a >> b;
        if (a == b)
        {
            cout << "1\n";
            continue;
        }
        ll l = 1, r = (b - a), ans, mid, cha = r;
        while (l <= r)
        {
            mid = (l + r) / 2;
            // cout << l << ' ' << r << ' ' << ans << '\n';
            if (mid * (mid + 1) / 2 <= cha)
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}