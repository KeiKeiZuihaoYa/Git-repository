#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

int n;
int fx[4] = {-1, 1, 0, 0};
int fy[4] = {0, 0, -1, 1};

inline bool in(int x, int y) { return x >= 0 && y >= 0 && x < n && y < n; }

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    vector<string> gra(n);
    vector<vector<int>> mp(n, vector<int>(n));

    for (auto &i : gra)
        cin >> i;

    auto work = [&](int a, int b, int tim)
    {
        queue<P> q;
        q.push({a, b});
        mp[a][b] = tim;
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + fx[i];
                int ny = y + fy[i];

                if (gra[nx][ny] == '#' && !mp[nx][ny])
                {
                    mp[nx][ny] = tim;
                    q.push({nx, ny});
                }
            }
        }
    };

    int tim = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (gra[i][j] == '#' && !mp[i][j])
                work(i, j, ++tim);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mp[i][j] == 0)
                continue;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + fx[k];
                int ny = j + fy[k];

                if (mp[nx][ny] == 0)
                {
                    mp[i][j] = -1;
                    break;
                }
            }
        }
    }

    set<int> us;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (mp[i][j] == -1 || mp[i][j] == 0)
                continue;
            us.insert(mp[i][j]);
        }

    cout << tim - (int)us.size();

    return 0;
}