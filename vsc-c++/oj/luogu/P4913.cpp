#include <bits/stdc++.h>
using namespace std;

struct node
{
    int lc, rc;
    int deep;
};

vector<node> tr;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, res = 0;
    cin >> n;
    tr.resize(n + 1);
    for (int i = 1, l, r; i <= n; i++)
    {
        cin >> l >> r;
        tr[i].lc = l;
        tr[i].rc = r;
    }

    tr[1].deep = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int l = tr[u].lc, r = tr[u].rc;
        if (l)
        {
            tr[l].deep = tr[u].deep + 1;
            q.push(l);
        }
        if (r)
        {
            tr[r].deep = tr[u].deep + 1;
            q.push(r);
        }
    }

    for (int i = 1; i <= n; i++)
        res = max(res, tr[i].deep);
    cout << res;

    return 0;
}