#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
#define int long long
struct node
{
    int t, d, l, vis = 0;
    bool operator<(const node &a) const
    {
        return t != a.t ? t < a.t : d < a.d;
    }
};

int n, t, d, l;
vector<node> v;

bool dfs(int cnt, int cur)
{
    if (cnt >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i].vis)
            continue;
        if (v[i].t + v[i].d < cur)
            return false;

        v[i].vis = 1;
        if (dfs(cnt + 1, v[i].l + max(cur, v[i].t)))
            return true;
        v[i].vis = 0;
    }
    return false;
}

void work()
{
    cin >> n;
    vector<node> v1(n);
    v.swap(v1);
    for (auto &i : v)
        cin >> i.t >> i.d >> i.l;

    sort(v.begin(), v.end());
    cout << (dfs(0, 0) ? "YES" : "NO") << '\n';
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