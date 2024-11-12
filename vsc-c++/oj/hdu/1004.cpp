#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<string, int> P;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while (cin >> n && n)
    {
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string x;
            cin >> x;
            mp[x]++;
        }

        P res = {"", 0};
        for (auto i : mp)
            if (i.second > res.second)
                res = i;

        cout << res.first << '\n';
    }

    return 0;
}