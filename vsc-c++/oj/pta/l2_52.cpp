#include <bits/stdc++.h>
using namespace std;
int l, n;
long long cnt;
vector<int> col(10), row(10);

void dfs(int x, int y)
{
    if (x >= n)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[j] != l)
                return;
        }
        cnt++;
    }
    else
    {
        for (int i = 0; i <= l; i++)
        {
            if (col[x] + i > l || row[y] + i > l)
                return;
            if (x == n - 1 && y > 0 && row[y - 1] != l)
                return;
            col[x] += i;
            row[y] += i;
            y++;
            if (y >= n)
            {
                if (col[x] == l)
                    dfs(x + 1, 0);
                else
                    goto nxt;
            }
            else
                dfs(x, y);
        nxt:
            y--;
            col[x] -= i;
            row[y] -= i;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> l >> n;
    dfs(0, 0);
    cout << cnt;

    return 0;
}