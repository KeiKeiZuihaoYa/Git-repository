#include <bits/stdc++.h>
using namespace std;
#define int long long

int fx[4] = {0, 1, 0, -1};
int fy[4] = {1, 0, -1, 0};

int n, m, h;
int a, b, c, d;
struct node
{
    int x, y, dis;
    bool operator<(const node &t) const
    {
        return dis > t.dis;
    }
};

signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // cin >> n >> m >> h;
    // cin >> a >> b >> c >> d;
    scanf("%d %d %d", &n, &m, &h);
    scanf("%d %d %d %d", &a, &b, &c, &d);

    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> dis(n, vector<int>(m, 1e9));
    for (auto &vec : v)
        for (auto &i : vec)
            scanf("%d", &i);

    int res;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    priority_queue<node> pq;
    pq.push({a, b, v[a][b]});

    while (!pq.empty())
    {
        node f = pq.top();
        pq.pop();

        if (vis[f.x][f.y])
            continue;
        vis[f.x][f.y] = true;

        if (f.x == c && f.y == d)
        {
            res = f.dis;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = f.x + fx[i];
            int ny = f.y + fy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny])
            {
                int nd = f.dis + v[nx][ny];
                pq.push({nx, ny, nd});
            }
        }
    }

    if (res >= h)
    {
        cout << "ohno\n";
        cout << res - h + 1;
    }
    else
    {
        cout << "zako~zako~\n";
        cout << h - res;
    }

    return 0;
}