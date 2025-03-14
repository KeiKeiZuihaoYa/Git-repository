#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;

int n, m;
int fx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int fy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

bool in(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector<vector<int>> mp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == 'O')
                mp[i][j] = 0;
            else
                mp[i][j] = 1;
    }

    int a, b, c, d;
    while (cin >> c >> d >> a >> b && a && b && c && d)
    {
        a--, b--, c--, d--;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // make ans
        vis[c][d] = -1;
        for (int i = 0; i < 8; i++)
        {
            int t1 = c, t2 = d;
            while (in(t1, t2) && mp[t1][t2] == 0)
            {
                vis[t1][t2] = -1;
                t1 += fx[i], t2 += fy[i];
            }
        }

        // for (auto &i : vis)
        // {
        //     for (auto &j : i)
        //         cout << j << ' ';
        //     cout << '\n';
        // }

        // find ans
        int res = -1;
        if (vis[a][b] == -1)
            res = 0;
        else
        {
            queue<P> q;
            q.push({a, b});
            vis[a][b] = 1;

            while (!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + fx[i], ny = y + fy[i];
                    if (!in(nx, ny) || mp[nx][ny] != 0 || vis[nx][ny] > 0)
                        continue;

                    if (vis[nx][ny] == -1)
                    {
                        res = vis[x][y];
                        goto nxt;
                    }
                    vis[nx][ny] = vis[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    nxt:
        if (res == -1)
            cout << "Poor Harry\n";
        else
            cout << res << '\n';
    }

    return 0;
}