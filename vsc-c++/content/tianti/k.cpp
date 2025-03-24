#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 2e5 + 10;
bitset<N> flag, vis, nowvis;
vector<vector<int>> v;
bool isTrue;

void dfs(int now)
{
    nowvis[now] = 1;
    if (v[now].size() != 2)
        isTrue = false;
    for (auto &i : v[now])
        if (!nowvis[i])
            dfs(i);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    v.resize(n);

    while (m--)
    {
        int u, _v;
        cin >> u >> _v;
        u--, _v--;
        v[u].push_back(_v);
        v[_v].push_back(u);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        isTrue = 1;
        if (vis[i])
            continue;
        dfs(i);
        vis |= nowvis;
        if (isTrue)
            res++;
    }
    cout << res;

    return 0;
}