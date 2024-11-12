#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int q, op, x, ans;
    set<int> s;
    cin >> q;
    while (q--)
    {
        cin >> op >> x;
        if (op == 1)
        {
            auto it = s.lower_bound(x);
            ans = (int)(it - s.begin() + 1);
        }
        if (op == 2)
        {
            auto it = s.begin() + x - 1;
            ans = *it;
        }
        if (op == 3)
        {
            auto it = s.find(x);
            if (it == s.begin())
                ans = -2147483647;
            else
                ans = *(--it);
        }
        if (op == 4)
        {
            auto it = find(x);
            if (it == s.end())
                ans = 2147483647;
            else
                ans = *(++it);
        }
        if (op == 5)
        {
            s.insert(x);
            continue;
        }
        cout << ans << '\n';
    }

    return 0;
}