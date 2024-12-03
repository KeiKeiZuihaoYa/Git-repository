#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, 1, -1};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, x, y, a, b, res;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));
    for (auto &i : g)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            i[j] = s[j] - '0';
    }

    cin >> x >> y >> a >> b;
    x--, y--, a--, b--;

    queue<P> q;
    q.push({x, y});

    vector<vector<int>> vis(n, vector<int>(n));
    vis[x][y] = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == a && y == b)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + fx[i], ny = y + fy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (g[nx][ny] || vis[nx][ny])
                continue;

            vis[nx][ny] = vis[x][y] + 1;
            q.push({nx, ny});
        }
    }

    cout << vis[a][b] - 1 << "\n";

    return 0;
}