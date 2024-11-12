#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f << 1;
const int N = 510;

vector<vector<int>> g(N);
bool vis[N][N];
int n, m, res;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int l[N][N], r[N][N], h[N][N];

inline bool in(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!in(nx, ny) || h[nx][ny] >= h[x][y])
            continue;
        if (!vis[nx][ny])
            dfs(nx, ny);
        l[x][y] = min(l[nx][ny], l[x][y]);
        r[x][y] = max(r[nx][ny], r[x][y]);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    memset(l, 0x3f, sizeof l);
    for (int i = 1; i <= m; i++)
        l[n][i] = r[n][i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> h[i][j];

    for (int i = 1; i <= m; i++)
        if (!vis[1][i])
            dfs(1, i);

    bool ok = true;
    for (int i = 1; i <= m; i++)
        if (!vis[n][i])
            ok = false, res++;

    if (!ok)
    {
        cout << "0\n"
             << res << endl;
        return 0;
    }

    int L = 1, R = r[1][1];
    while (L <= m)
    {
        for (int i = 1; i <= m; i++)
            if (l[1][i] <= L)
                R = max(R, r[1][i]);
        L = R + 1;
        res++;
    }

    cout << "1\n"
         << res << endl;
    return 0;
}