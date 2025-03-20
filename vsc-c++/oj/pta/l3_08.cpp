#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int N = 1e4 + 10;

int n, m, k;
unordered_map<int, vector<int>> mp;
bitset<N> bs;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    while (k--)
    {
        int a, now, dis;
        cin >> a;
        bs.reset();

        P res = {0, 0};
        queue<P> q;
        q.push({a, 0});
        while (!q.empty())
        {
            P front = q.front();
            q.pop();
            now = front.first, dis = front.second;

            if (bs[now])
                continue;
            bs[now] = 1;

            if (dis > res.second || (dis == res.second && now < res.first))
                res = front;

            vector<int> &nowv = mp[now];
            for (auto &i : nowv)
            {
                if (bs[i])
                    continue;
                q.push({i, dis + 1});
            }
        }

        cout << res.first << '\n';
    }

    return 0;
}