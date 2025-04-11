#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
unordered_map<int, multiset<int>> mp;

int n, w, res;

void dfs(int cnt, int &cur)
{
    if (cnt >= n)
    {
        if (cur == w)
            ++res;
        return;
    }
    for (auto &i : mp[cnt])
    {
        if (cur + i > w)
            return;
        cur += i;
        dfs(cnt + 1, cur);
        cur -= i;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> w;
    for (int i = 0, k, t; i < n; i++)
    {
        cin >> k;
        while (k--)
        {
            cin >> t;
            mp[i].insert(t);
        }
    }

    int t = 0;
    dfs(0, t);
    cout << res;

    return 0;
}