#include <bits/stdc++.h>
using namespace std;

int n;
int f[1010];

void init()
{
    for (int i = 1; i <= 1000; i++)
        f[i] = i;
}

int fafind(int x)
{
    return f[x] == x ? x : f[x] = fafind(f[x]);
}

void merge(int x, int y)
{
    x = fafind(x), y = fafind(y);
    if (x != y)
        f[x] = y;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    init();
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        int k = t[0] - '0', tt;
        vector<int> now;
        while (k--)
        {
            cin >> tt;
            now.push_back(tt);
        }
        v.push_back(now);
    }

    for (auto &i : v)
    {
        if (i.size() <= 1)
            continue;
        int x = i[0], y;
        for (int j = 1; j < i.size(); j++)
        {
            y = i[j];
            merge(x, y);
        }
    }

    unordered_map<int, int> mp;
    for (auto &i : v)
    {
        int nowf = fafind(f[i[0]]);
        mp[nowf]++;
    }

    vector<int> res;
    for (auto &[i, j] : mp)
        res.push_back(j);
    sort(res.begin(), res.end(), greater<int>());

    cout << res.size() << '\n';
    int i = 0;
    while (i != res.size())
    {
        cout << res[i++];
        cout << " \n"[i == res.size()];
    }

    return 0;
}