#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
typedef pair<int, int> P;

int n, m, ans = 1e7, cnt;
P p;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    unordered_map<int, int> mp;
    for (int i = 1; i <= m; i++)
        mp[i] = -1;

    int l = 0, r = 0;
    mp[a[l]]++, cnt = 1;
    while (r < n)
    {
        if (cnt == m)
        {
            if (r - l + 1 < ans)
            {
                ans = r - l + 1;
                p = {l, r};
            }
            if (--mp[a[l++]] == -1)
                cnt--;
        }
        else
        {
            if (++r == n)
                break;

            if (mp[a[r]] == -1)
                cnt++;
            mp[a[r]]++;
        }
    }
    cout << p.first + 1 << ' ' << p.second + 1;

    return 0;
}