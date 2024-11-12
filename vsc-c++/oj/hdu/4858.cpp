#include <bits/stdc++.h>
using namespace std;

void work()
{
    int n, m, q, op, x, y, cnt;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    vector<int> val(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    cin >> q;
    while (q--)
    {
        cin >> op >> x;
        if (op == 0)
        {
            cin >> y;
            val[x] += y;
        }
        else
        {
            cnt = 0;
            for (auto i : a[x])
                cnt += val[i];
            cout << cnt << '\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}