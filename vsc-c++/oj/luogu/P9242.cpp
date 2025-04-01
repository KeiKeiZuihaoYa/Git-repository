#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &i : a)
        cin >> i;

    unordered_map<char, int> mp;
    for (char i = '0'; i <= '9'; i++)
        mp[i] = 0;
    for (auto &i : a)
    {
        auto f = mp.find(i.front()), b = mp.find(i.back());
        int &fv = f->second, bv = b->second;
        b->second = max(bv, fv + 1);
    }

    int ans = 0;
    for (auto &[i, j] : mp)
        ans = max(ans, j);
    cout << n - ans;

    return 0;
}