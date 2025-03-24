#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

vector<int> col, res;
vector<vector<int>> v;

void dfs(int now, unordered_map<int, int> &q)
{
    priority_queue<P> nowq;
    unordered_map<int, int> mp;
    mp[col[now]]++;
    for (auto &i : v[now])
    {
        dfs(i, mp);
    }
    for (auto &[i, j] : mp)
        nowq.push({j, i}), q[i] += j;

    int maxx = nowq.top().first;
    while (!nowq.empty())
    {
        P front = nowq.top();
        nowq.pop();
        if (front.first != maxx)
            break;
        res[now] += front.second;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    col.resize(n);
    res.resize(n);
    v.resize(n);

    for (auto &i : col)
        cin >> i;

    for (int i = 1; i < n; i++)
    {
        int u, _v;
        u--, _v--;
        cin >> u >> _v;
        v[u].push_back(_v);
    }

    unordered_map<int, int> q;
    dfs(0, q);
    for (auto &i : res)
        cout << i << ' ';

    return 0;
}