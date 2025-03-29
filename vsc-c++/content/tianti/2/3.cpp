#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int m, n;
    cin >> m >> n;
    vector<ll> v(10);
    string tmp;
    for (int i = m; i <= n; ++i)
    {
        tmp = to_string(i);
        for (auto &i : tmp)
            v[i - '0']++;
    }

    for (auto &i : v)
        cout << i << ' ';

    return 0;
}