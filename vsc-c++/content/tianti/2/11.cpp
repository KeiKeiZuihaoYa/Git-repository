#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long
typedef pair<ll, ll> P;

ll Longlongmax = 9e15;
ll xb, yb, xe, ye, res = Longlongmax;
P fin;

unordered_map<ll, vector<P>> mp;
map<P, bool> s, vis;

bool in(const P &p)
{
    return s.count(p);
}

// int fx[4] = {0, 0, 1, -1};
// int fy[4] = {1, -1, 0, 0};

int fx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int fy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

struct node
{
    P now;
    ll cnt;
};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> xb >> yb >> xe >> ye;
    fin = {xe, ye};
    int _;
    cin >> _;
    while (_--)
    {
        ll line;
        P tmp;
        cin >> line >> tmp.first >> tmp.second;
        mp[line].push_back(tmp);
    }

    for (auto &[i, vec] : mp)
    {
        sort(vec.begin(), vec.end());
        ll l = vec[0].first, r = vec[0].second, j = 1, n = vec.size();
        while (j < n)
        {
            if (vec[j].first <= r)
                r = max(r, vec[j].second), j++;
            else
            {
                for (int t = l; t <= r; t++)
                    s[{i, t}] = true;
                l = vec[j].first, r = vec[j].second;
                j++;
            }
        }
        for (int t = l; t <= r; t++)
            s[{i, t}] = true;
    }

    queue<node> q;
    P be = {xb, yb};
    q.push({be, 0});
    while (!q.empty())
    {
        node front = q.front();
        q.pop();
        ll nowx = front.now.first, nowy = front.now.second, nowcnt = front.cnt;

        if (front.now == fin)
        {
            res = nowcnt;
            break;
        }

        vis[front.now] = 1;

        for (int i = 0; i < 8; i++)
        {
            ll nx = nowx + fx[i], ny = nowy + fy[i];
            if (!in({nx, ny}))
                continue;
            if (vis[{nx, ny}])
                continue;

            vis[{nx, ny}] = 1;
            q.push({{nx, ny}, nowcnt + 1});
        }
    }

    if (res != Longlongmax)
        cout << res;
    else
        cout << -1;

    return 0;
}