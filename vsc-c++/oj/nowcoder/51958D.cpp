#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int f[3] = {1, 10, 100};
inline bool in(int v) { return v >= 10 && v <= 300; }

int vis[310];
int solve(int x)
{
    memset(vis, 0, sizeof vis);
    int now = 10;

    queue<int> q;
    q.push(now), vis[now] = 1;
    q.push(300), vis[300] = 2;
    while (!q.empty())
    {
        int front = q.front(), nxval;
        q.pop();

        if (front == x)
            break;

        for (int i = 0; i < 3; i++)
        {
            nxval = front + f[i];
            if (in(nxval) && !vis[nxval])
                vis[nxval] = 1 + vis[front], q.push(nxval);

            nxval = front - f[i];
            if (in(nxval) && !vis[nxval])
                vis[nxval] = 1 + vis[front], q.push(nxval);
        }
    }
    return vis[x] - 1;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _;
    cin >> _;
    while (_--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve(a) + solve(b) + solve(c) + solve(d) << '\n';
    }

    return 0;
}