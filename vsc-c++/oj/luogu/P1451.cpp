#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int fx[4] = {0, 1, 0, -1}, fy[4] = {1, 0, -1, 0};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, res = 0;
    cin >> n >> m;
    vector<vector<int>> mp(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            mp[i][j] = s[j] - '0';
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j] && mp[i][j])
            {
                queue<P> q;
                q.push({i, j});
                vis[i][j] = 1;
                res++;
                while (!q.empty())
                {
                    P t = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int x = t.first + fx[k], y = t.second + fy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && mp[x][y])
                        {
                            vis[x][y] = 1;
                            q.push({x, y});
                        }
                    }
                }
            }
            
    cout << res << endl;

    return 0;
}