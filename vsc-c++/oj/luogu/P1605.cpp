#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

int n, m, t, res;
int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, -1, 1};

inline bool in(int x, int y) { return x >= 1 && y >= 1 && x <= n && y <= m; }

vector<vector<int>> vis, zhang;
int bx, by, ex, ey;

void dfs(int x, int y)
{
    if (x == ex && y == ey)
    {
        ++res;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + fx[i], ny = y + fy[i];
        if (!in(nx, ny) || vis[nx][ny] || zhang[nx][ny])
            continue;

        vis[nx][ny] = 1;
        dfs(nx, ny);
        vis[nx][ny] = 0;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> t;
    cin >> bx >> by >> ex >> ey;

    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    vector<vector<int>> z(n + 1, vector<int>(m + 1));
    vis.swap(v), zhang.swap(z);

    while (t--)
    {
        int a, b;
        cin >> a >> b;
        zhang[a][b] = 1;
    }

    vis[bx][by] = 1;
    dfs(bx, by);

    cout << res;

    return 0;
}