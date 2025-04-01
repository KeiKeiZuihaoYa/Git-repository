#include <bits/stdc++.h>
using namespace std;

struct node
{
    int t, d, l;
    bool operator<(const node &a) const
    {
        return t < a.t;
    }
};

bool flag;
int n;
vector<node> v;
vector<bool> vis;

inline bool between(int a, int b, int c)
{
    return a <= b && b <= c;
}

void dfs(int now, int nowtime)
{
    if (now >= n)
    {
        flag = true;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || nowtime > v[i].t + v[i].d)
            continue;
        vis[i] = 1;
        dfs(now + 1, max(nowtime, v[i].t) + v[i].l);
        if (flag)
            return;
        vis[i] = 0;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _;
    cin >> _;
    while (_--)
    {
        cin >> n;
        v.resize(n);
        vis.assign(n, false);
        flag = 0;

        for (auto &i : v)
            cin >> i.t >> i.d >> i.l;

        sort(v.begin(), v.end());

        dfs(0, 0);
        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}