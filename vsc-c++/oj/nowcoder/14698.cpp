#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define ll long long
const int inf = 0x3f3f3f3f << 1;

int fx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int fy[8] = {0, 0, -1, 1, -1, 1, 1, -1};

int n;
vector<string> gra1, gra2;
vector<vector<int>> f1, f2;

inline bool in(int x, int y) { return x >= 0 && y >= 0 && x < 4 && y < n; }

void work(int aim, int x, int y, int tim)
{
    queue<P> q;
    q.push({x, y});
    (aim == 1 ? f1[x][y] : f2[x][y]) = tim;
    while (!q.empty())
    {
        int nowx = q.front().first, nowy = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = nowx + fx[i], ny = nowy + fy[i];
            if (!in(nx, ny))
                continue;
            if ((aim == 1 ? f1[nx][ny] : f2[nx][ny]))
                continue;
            if ((aim == 1 ? gra1[nx][ny] : gra2[nx][ny]) == '.')
                continue;

            (aim == 1 ? f1[nx][ny] : f2[nx][ny]) = tim;
            q.push({nx, ny});
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    vector<string> v1(4), v2(4);
    vector<vector<int>> v3(4, vector<int>(n)), v4(4, vector<int>(n));
    gra1.swap(v1), gra2.swap(v2);
    f1.swap(v3), f2.swap(v4);

    for (auto &i : gra1)
        cin >> i;
    for (auto &i : gra2)
        cin >> i;

    for (int i = 0, tim = 0; i < 4; i++)
        for (int j = 0; j < n; j++)
            if (gra1[i][j] == '*' && f1[i][j] == 0)
                work(1, i, j, ++tim);

    for (int i = 0, tim = 0; i < 4; i++)
        for (int j = 0; j < n; j++)
            if (gra2[i][j] == '*' && f2[i][j] == 0)
                work(2, i, j, ++tim);

    unordered_map<int, int> mp1, mp2;
    for (auto &vec : f1)
        for (auto &i : vec)
            if (i)
                ++mp1[i];
    for (auto &vec : f2)
        for (auto &i : vec)
            if (i)
                ++mp2[i];

    if (mp1.size() > mp2.size())
    {
        cout << -1;
        return 0;
    }

    int sz1 = mp1.size(), res = 0;
    vector<int> v;
    for (auto &[i, j] : mp2)
        v.push_back(j);
    sort(v.begin(), v.end());
    for (int i = sz1 - 1; i < v.size(); i++)
        res += v[i];
    cout << res;

    return 0;
}