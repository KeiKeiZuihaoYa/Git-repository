#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f << 1;
const int N = 2e5 + 10;
int f[N], res = inf, d[N];

int find(int x)
{
    if (f[x] == x)
        return x;
    int fx = f[x];
    f[x] = find(f[x]);
    d[x] += d[fx];

    return f[x];
}

void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
        f[fx] = fy, d[x] = d[y] + 1;
    else
        res = min(res, d[x] + d[y] + 1);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        f[i] = i;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        merge(i, x);
    }

    cout << res;

    return 0;
}