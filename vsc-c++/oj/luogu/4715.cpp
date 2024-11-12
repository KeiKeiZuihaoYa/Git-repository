#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int dfs(int f, int x)
{
    if (x == 0)
        return f;
    else
    // return max(dfs(f, x - 1), dfs(f + (1 << x - 1), x - 1));
    {
        int a = dfs(f, x - 1);
        int b = dfs(f + (1 << x - 1), x - 1);
        return v[a] > v[b] ? a : b;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    v.resize(pow(2, n));

    for (auto &i : v)
        cin >> i;

    int a = dfs(0, n - 1);
    int b = dfs((1 << n - 1), n - 1);
    cout << (v[a] > v[b] ? b + 1 : a + 1);

    return 0;
}