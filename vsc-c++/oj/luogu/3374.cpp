#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int c[N], n, m;
#define lowbit(x) (x) & (-x)
int sum(int i) // a[1] + a[2] + ... + a[i]
{
    int res = 0;
    for (; i > 0; i -= lowbit(i))
        res += c[i];
    return res;
}
int sum(int i, int j) // a[i] + a[i+1] + ... + a[j-1] + a[j]
{
    return sum(j) - sum(i - 1);
}
void add(int i, int val) // a[i] += val
{
    for (; i <= n; i += lowbit(i))
        c[i] += val;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        add(i, x);
    }
    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            add(x, y);
        }
        else
        {
            cout << sum(x, y) << '\n';
        }
    }

    return 0;
}