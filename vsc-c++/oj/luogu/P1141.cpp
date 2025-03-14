#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int fx[4] = {0, 1, 0, -1}, fy[4] = {1, 0, -1, 0};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mp(n, vector<int>(n));
    vector<vector<int>> vis(n, vector<int>(n));
    vector<vector<int>> ans(n, vector<int>(n));
    for (auto &v : mp)
    {
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
            v[i] = s[i] - '0';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                int it = 0;
                vector<P> v;
                v.push_back({i, j});
                vis[i][j] = 1;

                while (it < v.size())
                {
                    int x = v[it].first, y = v[it].second;

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + fx[k], ny = y + fy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && mp[nx][ny] != mp[x][y])
                        {
                            v.push_back({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                    it++;
                }

                for (auto &[x, y] : v)
                    ans[x][y] = v.size();
            }
        }
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << ans[a][b] << '\n';
    }

    return 0;
}