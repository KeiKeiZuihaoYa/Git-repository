#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;

int fx[4] = {0, 1, 0, -1}, fy[4] = {1, 0, -1, 0};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int w, h;
    while (cin >> w >> h && w && h)
    {
        vector<vector<int>> a(h, vector<int>(w));
        vector<vector<int>> vis(h, vector<int>(w));
        for (auto &i : a)
        {
            string s;
            cin >> s;
            for (int j = 0; j < w; j++)
                if (s[j] == '.')
                    i[j] = 0;
                else if (s[j] == '#')
                    i[j] = 1;
                else
                    i[j] = 2;
        }

        P beginning;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                if (a[i][j] == 2)
                {
                    beginning = {i, j};
                    break;
                }
            }

        int ans = 0;
        queue<P> q;
        q.push(beginning);
        vis[beginning.first][beginning.second] = 1;
        while (!q.empty())
        {
            P now = q.front();
            q.pop();
            ans++;

            for (int i = 0; i < 4; i++)
            {
                int x = now.first + fx[i];
                int y = now.second + fy[i];

                if (x < 0 || x >= h || y < 0 || y >= w || vis[x][y] || a[x][y] == 1)
                    continue;

                vis[x][y] = 1;
                q.push({x, y});
            }
        }
        cout << ans << '\n';
    }

    return 0;
}