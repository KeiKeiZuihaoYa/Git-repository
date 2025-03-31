#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 1e5 + 10;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> c(N);
    for (auto &i : v)
        cin >> i;

    sort(v.begin(), v.end());

    for (auto &i : v)
    {
        for (int j = 1; j * j <= i; ++j)
            if (i % j == 0)
            {
                c[j].push_back(i);
                if (i / j != j)
                    c[i / j].push_back(i);
            }
    }

    for (int i = N - 1; i >= 0; --i)
    {
        if (c[i].size() < 3)
            continue;
        for (int j = 0; j < 3; j++)
            cout << c[i][j] << ' ';
        break;
    }

    return 0;
}