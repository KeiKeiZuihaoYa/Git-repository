#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, x, y;
    while (cin >> n >> m && n && m)
    {
        unordered_map<int, multiset<int>> xd, yd;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            xd[x].insert(y);
            yd[y].insert(x);
        }
        for (int i = 0, op, d; i < m; i++)
        {
            cin >> op >> d;
            if (op == 0)
            {
                cout << xd[d].size() << '\n';
                for (auto j : xd[d])
                    yd[j].erase(d);
                xd.erase(d);
            }
            else
            {
                cout << yd[d].size() << '\n';
                for (auto j : yd[d])
                    xd[j].erase(d);
                yd.erase(d);
            }
        }
        cout << '\n';
    }

    return 0;
}