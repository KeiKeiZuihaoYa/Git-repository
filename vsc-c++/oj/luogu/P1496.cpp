#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<P> v(n);
    for (auto &i : v)
        cin >> i.first >> i.second;
    sort(v.begin(), v.end());

    ll ans = 0;
    for (int i = 0, j = 1; i < n; j = i + 1)
    {
        int l = v[i].first, r = v[i].second;
        while (j < n && v[j].first <= r)
        {
            r = max(r, v[j].second);
            j++;
        }
        ans += r - l;
        i = j;
    }
    cout << ans << '\n';

    return 0;
}