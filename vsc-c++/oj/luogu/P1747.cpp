#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int fx[12] = {-2, -1, 1, 2, -2, -1, 1, 2, -2, -2, 2, 2};
int fy[12] = {-1, -2, -2, -1, 1, 2, 2, 1, -2, 2, -2, 2};

struct node
{
    int x, y, step;
};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    function<int()> solve = [&]()
    {
        int n, m;
        cin >> n >> m;

        if (n == 1 && m == 1)
            return 0;

        set<P> s;
        queue<node> q;
        q.push({n, m, 0});
        s.insert({n, m});

        while (!q.empty())
        {
            node f = q.front();
            q.pop();

            for (int i = 0; i < 12; i++)
            {
                int x = f.x + fx[i], y = f.y + fy[i];

                if (x <= 0 || y <= 0 || s.count({x, y}))
                    continue;

                if (x == 1 && y == 1)
                    return f.step + 1;

                q.push({x, y, f.step + 1});
                s.insert({x, y});
            }
        }
        return 0;
    };

    cout << solve() << '\n';
    cout << solve() << '\n';

    return 0;
}