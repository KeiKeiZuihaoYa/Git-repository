#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t, q, tmp;
    cin >> t;
    while (t--)
    {
        map<int, ll> s; // spot -> cnt sum
        cin >> n >> q;
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                s[a[i]]++;
                s[a[j] + 1]--;
            }

        map<ll, int> mp;
        ll cnt = 0;
        int lst = 1;
        for (auto i : s)
        {
            if (i.second < 0)
            {
                cnt += i.second;
                continue;
            }
            mp[cnt] += i.first - lst;
            cnt += i.second;
            lst = i.first;
        }

        while (q--)
        {
            cin >> tmp;
            cout << mp[tmp] << " \n"[q == 0];
        }
    }
    return 0;
}