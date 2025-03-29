#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

int fx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int fy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int mp[200][200];
int n, m;

bool in(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    queue<P> q;
    cin >> n >> m;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        for (int j = 0; j < m; j++)
            if (line[j] == '*')
                q.push({i, j});
    }

    while (!q.empty())
    {
        P front = q.front();
        q.pop();
        mp[front.first][front.second] = -1;

        for (int i = 0; i < 8; i++)
        {
            int nx = front.first + fx[i], ny = front.second + fy[i];
            if (in(nx, ny) && mp[nx][ny] != -1)
                mp[nx][ny]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (mp[i][j] != -1)
                cout << mp[i][j];
            else
                cout << '*';
        cout << '\n';
    }

    return 0;
}