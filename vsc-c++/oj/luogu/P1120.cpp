#include <bits/stdc++.h>
using namespace std;

int n, maxx, tot, ans;
vector<int> a;

bool dfs(int x)
{
    int tmp = tot / x;
    vector<int> v(tmp);

    
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    a.resize(n);
    for (auto &i : a)
        cin >> i;

    maxx = *max_element(a.begin(), a.end());
    tot = accumulate(a.begin(), a.end(), 0);

    sort(a.begin(), a.end());

    for (int i = maxx; i <= maxx + maxx; i++)
        if (tot % i == 0 && dfs(i))
        {
            ans = i;
            break;
        }

    cout << (ans ? ans : tot);

    return 0;
}