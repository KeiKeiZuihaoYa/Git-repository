#include <bits/stdc++.h>
using namespace std;

struct node
{
    char val;
    char l, r;
};

vector<node> v;
unordered_map<char, int> m;
void dfs(int now)
{
    cout << v[now].val;
    if (v[now].l != '*')
        dfs(m[v[now].l]);
    if (v[now].r != '*')
        dfs(m[v[now].r]);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v[i].val = s[0];
        v[i].l = s[1];
        v[i].r = s[2];
    }
    for (int i = 0; i < n; i++)
        m[v[i].val] = i;

    dfs(0);

    return 0;
}