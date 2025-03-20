#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct P
{
    int first, second;
    bool operator<(const P &a) const
    {
        return second > a.second;
    }
};

int n, m, d, k;
struct node
{
    int dis, pathLength, f;
    vector<P> ch;
    priority_queue<P> q;
};
vector<node> v;

inline int getInt(string s)
{
    int res = 0;
    if (s[0] == 'G')
        res = n + stoi(s.substr(1));
    else
        res = stoi(s);
    return res;
}

inline void add(int a, int b, int d)
{
    v[b].ch.push_back({a, d});
    v[a].ch.push_back({b, d});
}

void dfs(int now, int f, int dis, int pathLength)
{
    v[now].f = f;
    v[now].dis = dis;
    v[now].pathLength = pathLength;

    priority_queue<P> &nowq = v[now].q;
    for (auto &i : v[now].ch)
    {
        int nxtId = i.first, nxtIdDis = i.second + dis;
        if (nxtId == f)
            continue;
        dfs(nxtId, now, nxtIdDis, i.second);
        nowq.push({nxtId, nxtIdDis});
        if (nowq.size() > 2)
            nowq.pop();
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> k >> d;
    v.resize(n + 20);

    for (int i = 1; i <= k; i++)
    {
        string a, b;
        int dis, nodea, nodeb;
        cin >> a >> b >> dis;
        nodea = getInt(a), nodeb = getInt(b);
        add(nodea, nodeb, dis);
    }

    dfs(1, 0, 0, 0);

    return 0;
}