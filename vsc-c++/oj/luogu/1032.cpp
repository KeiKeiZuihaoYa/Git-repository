#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int ans = 20, maxx, minn = 1e9;
string a, b, t1, t2;
unordered_map<string, set<string>> rule;
unordered_map<string, bool> vis;

void dfs(string s, int step)
{
    if (s == b)
    {
        ans = min(ans, step);
        return;
    }
    if (step > 10 || step > ans)
        return;

    if (vis.find(s) != vis.end())
        return;
    vis[s] = true;

    // s.length () < b.length()
    if ((int)s.length() + maxx * (10 - step) < (int)b.length())
        return;
    // s.length() > b.length()
    if ((int)s.length() + minn * (10 - step) > (int)b.length())
        return;

    for (auto &[a, setb] : rule)
        for (int i = 0, al = a.length(), sl = s.length(); i + al <= sl; i++)
            if (s.substr(i, al) == a)
                for (auto &b : setb)
                {
                    string t = s;
                    t.replace(i, al, b);
                    dfs(t, step + 1);
                }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> a >> b;
    while (cin >> t1 >> t2)
    {
        if (t1 == t2)
            continue;
        rule[t1].insert(t2);
        int tmp = (int)t2.length() - (int)t1.length();
        maxx = max(maxx, tmp);
        minn = min(minn, tmp);
    }

    dfs(a, 0);
    if (ans == 20)
        cout << "NO ANSWER!" << endl;
    else
        cout << ans << endl;

    return 0;
}