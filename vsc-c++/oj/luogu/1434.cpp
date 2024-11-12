#include <bits/stdc++.h>
using namespace std;
const int N = 110;

int r, c, ans;
int mp[N][N];
int res[N][N];
int fx[4] = {0, 0, 1, -1};
int fy[4] = {1, -1, 0, 0};

int dfs(int i, int j)
{
    if (res[i][j])
        return res[i][j];
    res[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + fx[k];
        int y = j + fy[k];
        if (x <= 0 || y <= 0 || x > r || y > c || mp[x][y] >= mp[i][j])
            continue;
        res[i][j] = max(res[i][j], dfs(x, y) + 1);
    }
    ans = max(res[i][j], ans);
    return res[i][j];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            cin >> mp[i][j];
        }

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            dfs(i, j);
    cout << ans;
    return 0;
}