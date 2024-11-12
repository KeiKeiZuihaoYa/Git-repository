#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

const int N = 100000010; // 我的机器上int为4个字节

string s;
int res;
vector<int> avaday;
vector<P> avamonth;
map<int, bool> mp;
bool check(int x)
{
    if (x % 2 == 0)
        return x == 2;
    if (mp.find(x) == mp.end())
    {
        int limit = sqrt(x);
        for (int i = 3; i <= limit; i += 2)
            if (x % i == 0)
            {
                mp[x] = false;
                return false;
            }
        mp[x] = true;
        return true;
    }
}
void dfs1(int pos)
{
    if (pos >= 8)
    {
        int now = stoi(s.substr(6));
        if (check(now))
            return;
        if (now > 31 || now == 0)
            return;
        avaday.push_back(now);
    }
    else if (s[pos] == '-')
    {
        for (int i = 0; i <= 3; i++)
        {
            s[pos] = '0' + i;
            dfs1(pos + 1);
        }
    }
    else
        dfs1(pos + 1);
}

void dfs2(int pos)
{
    if (pos >= 6)
    {
        int m = stoi(s.substr(4, 2));
        if (m > 12 || !m)
            return;
        for (auto d : avaday)
        {
            if (m == 2) // 2月
            {
                if (d > 29)
                    continue;
            }
            // 31天的月
            else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            {
                if (d > 31)
                    continue;
            }
            else
            {
                if (d > 30)
                    continue;
            }
            if (vis[m * 100 + d])
                avamonth.push_back({m, d});
        }
    }
    else if (s[pos] == '-')
    {
        for (int i = 0; i <= 9; i++)
        {
            s[pos] = '0' + i;
            dfs2(pos + 1);
        }
    }
    else
        dfs2(pos + 1);
}

void dfs3(int pos)
{
    if (pos >= 4)
    {
        int now = stoi(s.substr(0, 4));
        for (auto &[m, d] : avamonth)
        {
            if (m == 2)
            {
                // 闰年
                if (now % 400 == 0 || (now % 4 == 0 && now % 100 != 0))
                {
                    if (d > 29)
                        continue;
                }
                else
                {
                    if (d > 28)
                        continue;
                }
            }
            int tmp = now * 10000 + m * 100 + d;
            res += vis[tmp];
        }
    }
    else if (s[pos] == '-')
    {
        for (int i = 0; i <= 9; i++)
        {
            s[pos] = '0' + i;
            dfs3(pos + 1);
        }
    }
    else
        dfs3(pos + 1);
}

void work()
{
    cin >> s;
    res = 0;
    avaday.clear(), avamonth.clear();

    dfs1(6);
    dfs2(4);
    dfs3(0);

    cout << res << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    euler();
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}