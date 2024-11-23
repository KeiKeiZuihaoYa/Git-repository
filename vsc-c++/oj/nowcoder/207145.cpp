#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int N = 1.5e5 + 10;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, res = 0;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    vector<P> v;
    for (int i = 0; i < n; i++)
        v.push_back({a[i], i});
    for (int i = 0; i < m; i++)
        v.push_back({b[i], i + n});
    sort(v.begin(), v.end(), [&](P p1, P p2)
         { return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first; });

    bitset<150000> ans, now;
    ans.set(), now.set();
    for (auto i : v)
        if (i.second < n)
            now[i.second] = 0;
        else
            ans &= now >> (i.second - n);

    // cout << ans << '\n'
    //      << now << '\n';
    for (int i = 0; i <= n - m; i++)
        res += ans[i];
    cout << res;

    return 0;
}