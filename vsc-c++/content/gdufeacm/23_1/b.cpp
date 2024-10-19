#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 5e3 + 10;

int fa[N], n, m, p;
int fafind(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = fafind(fa[x]);
}
void uni(int x, int y)
{
    x = fafind(x);
    y = fafind(y);
    if (x != y)
        fa[x] = fa[y];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        fa[i] = i;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        uni(a, b);
    }

    while (p--)
    {
        int a, b;
        cin >> a >> b;
        cout << ((fafind(a) == fafind(b)) ? "Yes\n" : "No\n");
    }

    return 0;
}