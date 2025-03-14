#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node
{
    ll u, v, w;
};
int n, m, k;
vector<ll> dis;
vector<node> v;

void Bellman()
{
    dis[0] = 0;
    for (int i = 0; i < k; i++)
    {
        vector<ll> tmp(dis);
        for (auto &j : v)
        {
            dis[j.v] = min(dis[j.v], tmp[j.u] + j.w);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    dis.resize(n, 1e10), v.resize(m);

    for (auto &i : v)
        cin >> i.u >> i.v >> i.w;
    for (auto &i : v)
        i.u--, i.v--;

    Bellman();

    if (dis.back() == 1e10)
        cout << "impossible";
    else
        cout << dis.back();

    return 0;
}