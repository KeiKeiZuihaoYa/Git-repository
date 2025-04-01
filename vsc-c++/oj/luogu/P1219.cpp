#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

int n, cnt;
bool in(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < n;
}

vector<int> res;
int fx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int fy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int col)
{
    if (col >= n)
    {
        if (cnt < 3)
        {
            for (auto &i : res)
                cout << i << ' ';
            cout << '\n';
        }
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0, x = col, y = i; j < 8; j++)
        {
            while (in(x, y))
            {
                if (res[x] == y)
                {
                    flag = 0;
                    goto nxt;
                }
                else
                    x += fx[j], y += fy[j];
            }
        }
    nxt:
        if (flag == false)
            continue;

        res[col] = i;
        dfs(col + 1);
        res[col] = -1;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    res.resize(n);
    for (auto &i : res)
        i = -1;
    dfs(0);

    return 0;
}