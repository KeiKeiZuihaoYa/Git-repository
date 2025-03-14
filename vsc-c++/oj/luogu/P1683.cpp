#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int fx[4] = {0, 1, 0, -1}, fy[4] = {1, 0, -1, 0};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int w, h;
    cin >> w >> h;
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

    // find beginning
    P beginning;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (a[i][j] == 2)
            {
                beginning = {i, j};
                break;
            }

    queue<P> q;
    q.push(beginning);
    int res = 0;
    while (!q.empty())
    {
        P cur = q.front();
        q.pop();
        res++;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + fx[i], ny = cur.second + fy[i];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w || vis[nx][ny] || a[nx][ny])
                continue;

            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    cout << res;

    return 0;
}